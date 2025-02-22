# Syslog Log Viewer - Çift Yönlü Bağlı Liste Kullanarak Syslog Kayıtlarını Okuma

Bu proje, Linux sistemlerindeki **/var/log/syslog** dosyasından syslog kayıtlarını okuyarak, bu kayıtları **çift yönlü bağlı liste** veri yapısı kullanarak saklayan ve ekrana yazdıran örnek bir C programıdır.

## Amaç

Bu programın amacı:
- **/var/log/syslog** dosyasından satır satır log kayıtlarını okuyarak,
- Her log mesajını dinamik olarak oluşturulan bir düğümde saklayıp,
- Çift yönlü bağlı liste yapısı ile logların saklanması, işlenmesi ve yazdırılmasını sağlamaktır.

---

## Özellikler

- **Dinamik Bellek Yönetimi:** Log kayıtları, dosyadan okunduğu anda dinamik olarak belleğe alınır.
- **Çift Yönlü Bağlı Liste:** Her log kaydı, hem ileri hem geri gezinmeyi mümkün kılan çift yönlü bağlı liste düğümü olarak tutulur.
- **Kolay Ekleme ve Temizleme:** Yeni kayıtlar listenin sonuna eklenir, program sonlandırılırken tüm düğümler serbest bırakılır.
- **Basit Dosya Okuma:** Standart C kütüphaneleri kullanılarak syslog dosyası okunur ve log mesajları ekrana basılır.

---
