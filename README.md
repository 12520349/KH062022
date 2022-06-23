## Phần điện
| Thành phần | Chức Năng |
| --- | --- |
| arduino uno + CNC Shield V3 GRBL + công tắc hành trình + cảm biến kim loại SN04 | Điều khiển 3 step X, Y , Z |
| arduino nano + BTS7960 + PCA9685| Điều khiển servo + động cơ DC bắn bóng |
| Raspi| Cung cấp giao diện người dùng và điều khiển truyền lệnh tới 2 con arduino UNO và Nano |

## Phần code:
| Thư viện sử dụng của Arduino | Chức Năng |
| --- | --- |
| Adafruit_PWMServoDriver | Điều khiển servo qua mạch PCA9685 |
| BTS7960 | Điều khiển động cơ DC bắn bóng |
