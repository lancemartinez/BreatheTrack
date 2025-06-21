Title: BreatheTrack Solar‑Powered PCB Design                                
Author: Lance Martinez                          
Description: Adding a solar panel, battery charger, protection, and boost stages to power our custom ESP32‑AQI sensor board from sunlight alone.                              
Date Created: 6/14/2025
---

## Total Time Spent: ~ 10 hours   

### June 3
Time Spent: ~2 hours  

Today I finished laying out every block on our BreatheTrack board: solar input and reverse‑protection diode, TP4056 charger, battery‑protection pair, Li‑ion header, boost converter, and the ESP32 & AQI sensor headers. No nets are routed yet—this was purely schematic placement to verify function and signal flow.



### June 5
Time Spent: ~2.5 hours  
I completed all power routing: from the solar connector through the charger and protection stages into the battery, then through the boost converter to the 5 V_SYS rail. I also dropped vias for ground and power plane connections. Next up is the signal routing and copper pours.



### June 10
Time Spent: ~1 hours  
After trimming the board to 80×50 mm, I poured the ground plane on the inner layer and the 5 V_SYS plane on the second inner layer. This cleaned up my return paths and freed F.Cu/B.Cu for all signal traces. The board outline now matches the planned enclosure footprint.



## June 14
Time Spent: ~2.5 hours  
After several wiring fixes, I ran a final DRC and got 0 errors, only three harmless warnings, and checked the 3D model to verify component clearances. All looks good for fabrication. Gerbers and drill files are now generated and ready for upload.











