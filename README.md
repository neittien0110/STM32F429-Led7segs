# EMBEDED SYSTEM / HỆ NHÚNG - STM32F429FzIT6 and Led 7-segs

## Overview
 
 Programming STM32F429FzIT6 to show decimal numbers on two __7-segs leds__, pluged on breadboard with 2 [2N2222 transistors](https://dientusangtaovn.com/transistor-2n2222/).

## Bill of Materials / Danh sách linh kiện

- 1 x [Breadboard cắm](https://chotroihn.vn/bo-test-mau-syb170)
- 2 x led 7 đoạn với [cathode (âm cực chung)](https://chotroihn.vn/led-7-thanh-0-56inch-katot-chung-sang-do)
- 2 x transistor [2N2222 transistors](https://dientusangtaovn.com/transistor-2n2222/).
- 8 x điện trở [330 Ohm](https://chotroihn.vn/tro-vach-1-4w-5-goi-50con-2)
- 20 x Dây căm breadboard [đực-đực](https://chotroihn.vn/day-cam-test-board-day-duc-duc-day-duc-cai-day-cai-cai-day-noi-7-mau-10cm)

## Breadboard / Bo mạch cắm

- Breadboard simulation at wowki: <https://wokwi.com/projects/425825654973202433> \
   ![image](https://github.com/user-attachments/assets/5f309d16-095a-4314-b1c5-67085fe5acda)
- The PING 7-seg Led on the left with __7 current limit resistances__, 220/330 Ohm standard circuit installation.\
  However, the BLUE 7-seg Led on the right with __1 current limit resitance__ at common cathode pin, simple and cheep but low quality.\
  __2 current limit resitances__, \
  3.3/4.7 kOhm for base poles of transistors\
  ![20250324_222504](https://github.com/user-attachments/assets/a970e2e3-84eb-4c42-8636-3df4dc3e19e1)
- Plug the 7-seg leds (colored by acrylic pens :blush: )\
  ![20250324_222529](https://github.com/user-attachments/assets/9dcc6426-4fe6-4c28-b373-83598ce267c0)
- Connect breadboard from \
  ![20250324_222705](https://github.com/user-attachments/assets/1a729962-eb79-4132-8f32-68b853c40db2)
- Connect breadboard to STM32F429-DISK1 at __PE8 ~ PE14 pin__.\
  ![20250324_222720](https://github.com/user-attachments/assets/b811e355-e700-4b02-9212-399b7020e38e)


## Videos
 - [7seg part1 - check 7-seg leds and transistors are working well ![thumbnail](https://github.com/user-attachments/assets/1c4b962a-4a9f-480f-b005-41f3c8af5352)](https://youtu.be/sPcrocyuKak)
 - [7seg part2 - control transistors to turn off/of 7-seg leds ![image](https://github.com/user-attachments/assets/64c19325-b07b-42d6-a7a7-1709efcb3bc8)](https://youtu.be/DgbDV2A6jI0)
 - [7seg part3 - control transistors and 7-seg. Wiring. ![image](https://github.com/user-attachments/assets/e7591208-1476-4d9c-ad2c-b342bbeed2c0)](https://youtu.be/NmXTEj0gcd8)
