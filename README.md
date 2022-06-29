## Phần điện
![alt text](https://github.com/12520349/KH062022/blob/main/so-do-ket-noi-arduino-cnc-shield-v3.png)
![alt text](https://github.com/12520349/KH062022/blob/main/bst7960.jpg)
![alt text](https://github.com/12520349/KH062022/blob/main/pca9685.jpg)

| Thành phần | Chức Năng |
| --- | --- |
| arduino uno + CNC Shield V3 GRBL + công tắc hành trình + cảm biến kim loại SN04 | Điều khiển 3 step X, Y , Z |
| arduino nano + BTS7960 + PCA9685| Điều khiển servo + động cơ DC bắn bóng |
| Raspi| Cung cấp giao diện người dùng và điều khiển truyền lệnh tới 2 con arduino UNO và Nano |
## Đi dây
![alt text](https://github.com/12520349/KH062022/blob/main/sodo1_bb.png)
![alt text](https://github.com/12520349/KH062022/blob/main/sodo_a4988_bb.png)


## Phần code:
| Thư viện sử dụng của Arduino | Chức Năng |
| --- | --- |
| Adafruit_PWMServoDriver | Điều khiển servo qua mạch PCA9685 |
| BTS7960 | Điều khiển động cơ DC bắn bóng |
