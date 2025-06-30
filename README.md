# BreatheTrack

### Project Description

This is a custom PCB we designed for our remote AQI sensing network called BreatheTrack. The BreatheTrack Network comprises of a central server with several AQI sensors that wirelessly transmit their sensor readings via HTTP through Flask. The BreatheTrack Sensors are built with the purpose to be inexpensive and minimal, providing key functionality without obstructing daily life.  

### Why we made it

A Single PCB reduces clutter and wiring issues from our initial prototype. Additionally, we have expanded functionality by adding support for a solar cell, which is accompanied by a Voltage regulator with protection to now allow the use of Lipo Batteries that can be charged through solar power. Additionally, PCBs significantly streamline our assembly process, allowing us to assemble multiple units in the time that it would take to assemble our original prototype. 


## Prototype CAD Design
![CAD](img/prototypecad.png)

## Fully Assembled Prototype 
![IRL](https://github.com/user-attachments/assets/fca9da71-7108-41bc-889d-3d14d4a01c25)

## New PCB Schematic
![Schematic](img/schematic.png)

## PCB 3D Render
![Board 3D](img/BreatheTrackBoard.png)

## Bill of Materials (BOM)

| Component                    | Quantity  | Price Estimate   | LINK               |
|------------------------------|-----------|------------------|--------------------|
| PCB                          | 1         | $60              | [JLCPCB](https://jlcpcb.com) |
| 6V 3W Solar Cell             | 3         | $10              | [AliExpress](https://www.aliexpress.us/item/3256807383974087.html?spm=a2g0o.productlist.main.1.35f3Ha3VHa3VaC&algo_pvid=d887562b-9add-46a8-9f8c-ddd5e3ba4c47&algo_exp_id=d887562b-9add-46a8-9f8c-ddd5e3ba4c47-0&pdp_ext_f=%7B%22order%22%3A%2225%22%2C%22eval%22%3A%221%22%7D&pdp_npi=4%40dis%21USD%213.50%213.08%21%21%213.50%213.08%21%40210318c317513249961495827e6246%2112000043061129476%21sea%21US%210%21ABX&curPageLogUid=cN9vS2Gpiolg&utparam-url=scene%3Asearch%7Cquery_from%3A) |
| LIPO Batteries               | 1         | $20              | [Amazon](https://www.amazon.com/MakerFocus-Rechargeable-Protection-Insulated-Development/dp/B0DK5BBKM5/ref=sr_1_1_sspa?crid=33OQHGAFZKI41&dib=eyJ2IjoiMSJ9.WxjcX56NXHt9QLH11mWqUr8ah2V-7YexDvRKFDypc_Ste3FNB4DZ87XmCklSCc_GQYk6X1cDK8Cr5RUoYhj4e8t50Zf1cUL4o1LINEvV78wg4Dr1zuqhdKYXm2TQeQ0o4MaYty67VVWkN8jyuigbkru99FalspddWxXD04Dsw-BlHhMRHNqKP_Z2K0Y9n930V-HqrzbBxV_xQp6gfhpZywY1I5s8BPuP8aNRSCHi-GyH2L-rwyq0ctQthRYZ7-H5hJHlxuBUmQjVDZSdlcYHdbHBwUt111QhPSkvP6DWJZo.m9foLkYSE_QwVjHuxX19zQt3dcjnOkfhIvHlSeVZYOQ&dib_tag=se&keywords=lipo%2Brechargeable%2Bbattery&qid=1751325128&sprefix=lipo%2Brecharg%2Bbattery%2Caps%2C727&sr=8-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&th=1) 
| TP4056 w/battery protection  | 1         | $10              | [Amazon](https://www.amazon.com/HiLetgo-Lithium-Charging-Protection-Functions/dp/B07PKND8KG/ref=sr_1_4?crid=1ZFK4LYI1WHD9&dib=eyJ2IjoiMSJ9.ya4DP46mvuUo9crjEmtl4cTs2D8GLBpbhxoat9FqxYarHE1xFFHvcrgYH1FbPZ4ZI6IOwfmxJ8ejFaFwloL7ypq0CwSoIccLmFvO5kScJE8X9u_NYNoeAWAJSC-wc2I_1APw7RsI5PV4-wk3H26Dqq2d8jViBEhCc49-d9JvBYAm_0DTEOPtzJUxQ-mPXUdTFD_-QO15r9RZ7VVP2K23sXtUhe-JJP1np1_op34yDBA.VhGV2hSfPTVJdioUXrRYrAzYh-SPukpoKlOSz5Y1b6o&dib_tag=se&keywords=tp4056+with+jst+and+protection&qid=1751325559&sprefix=tp4056+with+jst+and+protectio%2Caps%2C196&sr=8-4)| 
| MS1100 Gas Sensor            | 5         | $10              | [AliExpress](https://www.aliexpress.us/item/3256807137876184.html?spm=a2g0o.productlist.main.8.2ae16874iz54fJ&aem_p4p_detail=202506301627332151353802599940000572471&algo_pvid=87008f3a-64e3-412a-9294-49f03c961bdc&algo_exp_id=87008f3a-64e3-412a-9294-49f03c961bdc-7&pdp_ext_f=%7B%22order%22%3A%2219%22%2C%22eval%22%3A%221%22%7D&pdp_npi=4%40dis%21USD%2119.56%2112.56%21%21%21139.30%2189.44%21%402103010b17513260532001920e23ba%2112000040264201244%21sea%21US%210%21ABX&curPageLogUid=iq4k9BI5Jmd1&utparam-url=scene%3Asearch%7Cquery_from%3A&search_p4p_id=202506301627332151353802599940000572471_2#nav-review)|
| ESP-32 Dev Board             | 3         | $16              | [Amazon](https://www.amazon.com/ESP-WROOM-32-Development-Microcontroller-Integrated-Compatible/dp/B08D5ZD528/ref=sr_1_1?crid=29T7AWT8FLZUN&dib=eyJ2IjoiMSJ9.XBINg-sjhfF_gUtnMiKGjgAP6U086JzeO1Awny1CrbgATMnn0NsXBzTx6uR7rdOvV0KyHBRH7xGJQ-1txsZL4-raY_ZpZed26avafCQGlQx4vU2ZojpUB5SR50ZNDtg-dEKeStjXtiaWa4eUtw43j7jFwo5hhF-CIbCeFx1SBMuYvzDwbOJlZO2TYzPSjafmgl9yOV7o85J0J5WhXWZUANCB-1XrnT_6IBna_-tkcIk.pfvTzqabW5ZYoJiTyf5kVAlDRxw-CWowj79Mi1OWZQ8&dib_tag=se&keywords=esp32&qid=1751325882&sprefix=esp32%2Caps%2C157&sr=8-1&th=1) |








