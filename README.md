# Hệ thống IoT Quan Trắc ESP32-Wroom32 Devkit với PlatformIo

## Giới thiệu
Dự án này xây dựng một **hệ thống IoT quan trắc môi trường** sử dụng **ESP32 (Node WiFi 32)**, thu thập dữ liệu cảm biến và gửi về server qua Wi-Fi. Thiết bị tích hợp **webserver cấu hình**, **dashboard hiển thị dữ liệu**, và hỗ trợ cơ chế **cảnh báo thủ công hoặc tự động (AI/TinyML)**.

Dự án được phát triển bằng **PlatformIO**, lập trình bằng **C/C++**, hướng đến mô hình IoT thực tế cho thu thập dữ liệu, giám sát, và điều khiển.

## Mục lục
- [Giới thiệu](#gioi-thieu)
- [Công nghệ sử dụng](#cong-nghe-su-dung)
- [Các thành phần chính](#cac-thanh-phan-chinh)
  - [1. Cảm biến](#1-cam-bien)
  - [2. Webserver cấu hình trên ESP32](#2-webserver-cau-hinh-tren-esp32)
  - [3. Website Dashboard](#3-website-dashboard)
  - [4. Cơ chế cảnh báo](#4-co-che-canh-bao)
  - [5. AI / TinyML](#5-ai--tinyml)
- [Luồng hoạt động hệ thống](#luong-hoat-dong-he-thong)
- [Cách chạy dự án](#cach-chay-du-an)
- [Đóng góp](#dong-gop)
- [Giấy phép](#giay-phep)

---

## Công nghệ sử dụng
- **Nền tảng phát triển:** PlatformIO
- **Board:** ESP32 (Node WiFi 32)
- **Ngôn ngữ:** C/C++
- **Webserver:** ESPAsyncWebServer hoặc WebServer mặc định
- **Giao thức:** HTTP / MQTT
- **Dashboard:** HTML/CSS/JS
- **Lưu trữ cấu hình:** Preferences / EEPROM
- **AI/TinyML:** TensorFlow Lite Micro

---

## Các thành phần chính

### 1. Cảm biến
- Sử dụng ít nhất **hai cảm biến môi trường**, ví dụ:
  - DHT11/DHT22 (nhiệt độ – độ ẩm)
  - MQ-135 (chất lượng không khí)
  - DS18B20
  - Soil moisture sensor
- ESP32 đọc chu kỳ theo timer hoặc theo cấu hình người dùng.
- Gửi dữ liệu về server qua HTTP/MQTT.

### 2. Webserver cấu hình trên ESP32
- Tích hợp **WebServer ESP32** phục vụ giao diện cấu hình:
  - Wi-Fi SSID & Password
  - ID thiết bị
  - Chu kỳ gửi dữ liệu
- Giao diện chạy trực tiếp khi ESP32 phát Wi-Fi AP Mode lần đầu.
- Dữ liệu cấu hình được lưu vào **EEPROM / Preferences**.

### 3. Website Dashboard
- Hiển thị dữ liệu cảm biến theo thời gian thực.
- Biểu đồ, bảng dữ liệu lịch sử.
- Cho phép chỉnh cấu hình thiết bị:
  - Ngưỡng cảnh báo
  - Chu kỳ gửi dữ liệu
  - Tùy chọn cảm biến
- Có thể mở rộng thành webapp hoặc mobile app.

### 4. Cơ chế cảnh báo
Hệ thống hỗ trợ hai chế độ:

#### **TH1: Chế độ cảnh báo tự động (AI/TinyML)**
- Phân tích dữ liệu cảm biến theo thời gian.
- Phát hiện bất thường (anomaly detection).
- Dự đoán trạng thái môi trường.

#### **TH2: Chế độ cảnh báo thủ công**
- Người dùng thiết lập ngưỡng trên Dashboard.
- Khi giá trị vượt ngưỡng → cảnh báo qua web/app hoặc LED/Buzzer.

### 5. AI / TinyML
- Sử dụng TinyML để phát hiện bất thường.
- Mô hình nhẹ dạng `.tflite` chạy trực tiếp trên ESP32.
- Ứng dụng: cảnh báo chất lượng không khí, dự đoán nhiệt độ, đánh giá an toàn môi trường.

---

## Luồng hoạt động hệ thống
  1. ESP32 khởi động → kiểm tra cấu hình Wi-Fi.
  2. Nếu chưa cấu hình → bật AP mode + mở trang web cấu hình.
  3. Người dùng nhập SSID/Password → ESP32 kết nối Wi-Fi.
  4. ESP32 đọc dữ liệu cảm biến theo chu kỳ.
  5. Dữ liệu được gửi về server và hiển thị tại Dashboard.
  6. Nếu có cảnh báo (AI hoặc ngưỡng): kích hoạt thông báo.
  7. Người dùng có thể điều chỉnh cấu hình từ Dashboard.

---

## Cách chạy dự án

### 1. Clone repository
```sh
git clone https://github.com/nguyenthinhthanh/ESP32-IoT-Monitoring-System-using-PlatformIo
```

### 2. Mở bằng PlatformIO (VS Code)
```sh
Vào File → Open Folder → chọn thư mục dự án.

Chọn board: ESP32 Dev Module
```

### 3. Flash chương trình
```sh
pio run --target upload
```

### 4. Mở serial monitor
```sh
pio device monitor
```

### 5. Cấu hình thiết bị lần đầu
```sh
Kết nối vào Wi-Fi AP của ESP32.

Mở trình duyệt và truy cập:
http://192.168.4.1
```

## Đóng góp
Bạn có ý tưởng cải thiện trò chơi? Hãy mở Pull Request hoặc Issue trên GitHub!

## Giấy phép
Dự án này được tạo ra **chỉ nhằm mục đích học tập**. Không được sử dụng cho mục đích thương mại.

