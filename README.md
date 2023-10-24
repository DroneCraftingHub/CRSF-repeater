# CRSF-repeater

## Використання Arduino для репітера є надлишковим (оскільки можна використовувати пряму підключення), однак даний проєкт – гарна точка для старту для випадків, коли потрібна додаткова обробка повідомлень

![Діаграма підключення](https://github.com/DroneCraftingHub/CRSF-repeater/blob/main/diagram.png?raw=true)

Використовувався і в домашніх умовах протестувався наступний сетап:
- Пульт Jumper T-Pro ELRS 2.4 GHz (Далі просто "пульт")
- ELRS BetaFPV Lite RX 2.4 GHz (Далі "наземний RX")
- ELRS BetaFPV Micro TX 915 MHz (Далі "трансміттер")
- ELRS BetaFPV SuperD RX 915 MHz (Далі "віддалений RX")
- Arduino Nano
- 2S/3S/4S батарея підключена в BEC 5v

Всі ELRS учасники прошиті на 3.3.0

Наземний RX - після прошивки підключитись до WiFi та в опціях обрати Baud Rate 400000

Трансміттер – після прошивки підключитись до WiFi та в опціях перевірити чи вимкнута (і вимкнути якщо увімкнена) опція "UART Inverted"

## З'єднання:
- У моєму сетапі я під'єднував BEC до ардуїно в піни Ground та VIN
- Наземний RX під'єднаний до пінів 5v та Ground
- До них же (5v та Ground) під'єднане живлення трансміттеру

TX наземного RX-а під'єднаний до RX0 Arduino. CRSF порт (у моєму випадку він одножильний) трансміттера під'єднаний до TX1 Arduino. Arduino повинен мати спільний Ground з трансміттером та наземним RX-ом

### Я б рекомендував наступний порядок дій:
1. З'єднуєте кабелі живлення як описано в *З'єднання*, сигнальні кабелі поки не підключаєте
2. Прошиваєте на прошивку 3.3.0 (буде працювати і на інших версіях прошивок, скоріше всього, але я не пробував) або вище все ваше ELRS радіообладнання
3. Заливаєте скетч з цього репозиторію в Arduino. Від'єднуєте живлення.
4. Під'єднуєте сигнальні кабелі.
5. Bind-ите пульт з наземним RX-ом, трансміттер з віддаленим RX-ом
6. В налаштуваннях трансміттеру вибираєте Packet Rate > 50Hz, щоб не було великої затримки

Повинно працювати 🙂
Щоб перевірити – під'єднайте ваш віддалений RX до польотного контроллеру та зайдіть у вкладку Receiver. Канали повинні відображатись адекватно тому як у вас в пульті.

# Що не буде працювати:
- Телеметрія віддаленого RX-а не буде отримуватись на пульт
- Link negotiation ітд

## Припускаєтсья що подібний сетап на цьому скетчі повинен працювати з будь-якими іншими ELRS та кросфайр комбінаціями, проте це ще не перевірялось.
