#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 512  // Maksimum log satır uzunluğu

// Çift yönlü bağlı liste düğüm yapısı
struct LogEntry {
    char message[MAX_LOG_SIZE];
    struct LogEntry* prev;
    struct LogEntry* next;
};

// Yeni düğüm oluşturma
struct LogEntry* createLogEntry(char* logMessage) {
    struct LogEntry* newEntry = (struct LogEntry*)malloc(sizeof(struct LogEntry));
    if (newEntry == NULL) {
        printf("Bellek tahsis hatasi!\n");
          exit(1);
    }
    strncpy(newEntry->message, logMessage, MAX_LOG_SIZE);
    newEntry->prev = NULL;
    newEntry->next = NULL;
    return newEntry;
}

// Listeye log ekleme (sona ekleme)
void addLog(struct LogEntry** head, struct LogEntry** tail, char* logMessage) {
    struct LogEntry* newEntry = createLogEntry(logMessage);

    if (*head == NULL) {
        *head = *tail = newEntry;
        return;
    }

    (*tail)->next = newEntry;
    newEntry->prev = *tail;
    *tail = newEntry;
}

// Logları yazdırma (ileri yönde)
void printLogs(struct LogEntry* head) {
    struct LogEntry* temp = head;
    printf("\n--- Syslog Kayitlari---\n");
    while (temp != NULL) {
        printf("%s", temp->message);
        temp = temp->next;
    }
}

// Logları temizleme (belleği serbest bırakma)
void freeLogs(struct LogEntry* head) {
    struct LogEntry* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    FILE* file = fopen("/var/log/syslog", "r");
    if (file == NULL) {
        printf("Syslog dosyasi acilamadi!\n");
        return 1;
    }

    struct LogEntry* head = NULL;
    struct LogEntry* tail = NULL;
    char logBuffer[MAX_LOG_SIZE];

    // Syslog dosyasını satır satır okuyup bağlı listeye ekliyoruz
    while (fgets(logBuffer, MAX_LOG_SIZE, file)) {
        addLog(&head, &tail, logBuffer);
    }

    fclose(file);

    // Logları yazdırma
    printLogs(head);

    // Belleği temizleme
    freeLogs(head);
    return 0;
}
