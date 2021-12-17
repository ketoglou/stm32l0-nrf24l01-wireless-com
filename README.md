# Radio Frequency Wireless Communication

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)\
![MCU](https://img.shields.io/badge/MCU-STM32-blue)
![MCU Family](https://img.shields.io/badge/Family-L0-yellow)
![MCU Model](https://img.shields.io/badge/Model-11K4-yellow)
![IDE](https://img.shields.io/badge/STM32CubeIDE-blue)
![firmware-size](https://img.shields.io/badge/Firmware%20Size-2.95%20kB-red)
![ram-usage](https://img.shields.io/badge/RAM%20Usage-1.12%20kB-red)

This project demonstrates RF wireless communication with the use
of STM32L011K4 as MCU and nRF24L01+ as RF IC. One "Hello" message
is send from nRF24L01+ transmitter to nRF24L01+ receiver. Then the
receiver perform an equality check and if it is matched a LED is
blink. The communication use the Enhanced ShockBurst wireless protocol.
The communication is half-duplex (cannot receive only when send). For
development i have used STM32CubeIDE with bare metal code.

## <span style="color:red">RF Characteristics</span>
```diff
+ Modulation:			GFSK   
+ Frequency:			2.4 GHz
+ Data Rate:			2   Mbps
```

## Hardware
| Pin | Usage       |
|-----|-------------|
| PA8 | nRF24L01+ INT  |
| PA7 | nRF24L01+ MOSI |
| PA6 | nRF24L01+ MISO |
| PA5 | nRF24L01+ SCK  |
| PA4 | nRF24L01+ CS   |
| PB1 | nRF24L01+ CE   |
| PB3 | LED	       |

## Flashing
Import the project to STM32CubeIDE and build it or build it directly
with gcc-arm-none-eabi. Flash it and you are ready.
