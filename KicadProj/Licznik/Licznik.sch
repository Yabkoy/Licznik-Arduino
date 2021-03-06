EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L power:PWR_FLAG #FLG01
U 1 1 60A6240E
P 10550 850
F 0 "#FLG01" H 10550 925 50  0001 C CNN
F 1 "PWR_FLAG" H 10550 1023 50  0000 C CNN
F 2 "" H 10550 850 50  0001 C CNN
F 3 "~" H 10550 850 50  0001 C CNN
	1    10550 850 
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG02
U 1 1 60A6361C
P 10850 1100
F 0 "#FLG02" H 10850 1175 50  0001 C CNN
F 1 "PWR_FLAG" H 10850 1273 50  0000 C CNN
F 2 "" H 10850 1100 50  0001 C CNN
F 3 "~" H 10850 1100 50  0001 C CNN
	1    10850 1100
	-1   0    0    1   
$EndComp
$Comp
L power:+5V #PWR011
U 1 1 60A65C8E
P 10550 1100
F 0 "#PWR011" H 10550 950 50  0001 C CNN
F 1 "+5V" H 10565 1273 50  0000 C CNN
F 2 "" H 10550 1100 50  0001 C CNN
F 3 "" H 10550 1100 50  0001 C CNN
	1    10550 1100
	-1   0    0    1   
$EndComp
Wire Wire Line
	10850 850  10850 1100
Wire Wire Line
	10550 850  10550 1100
$Comp
L Device:C C2
U 1 1 60A72311
P 5450 2800
F 0 "C2" V 5198 2800 50  0000 C CNN
F 1 "C" V 5289 2800 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P2.50mm" H 5488 2650 50  0001 C CNN
F 3 "~" H 5450 2800 50  0001 C CNN
	1    5450 2800
	0    1    1    0   
$EndComp
$Comp
L Device:C C1
U 1 1 60A7353E
P 4850 2800
F 0 "C1" V 4598 2800 50  0000 C CNN
F 1 "C" V 4689 2800 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P2.50mm" H 4888 2650 50  0001 C CNN
F 3 "~" H 4850 2800 50  0001 C CNN
	1    4850 2800
	0    1    1    0   
$EndComp
$Comp
L Device:R R1
U 1 1 60A737E1
P 3600 2700
F 0 "R1" H 3670 2746 50  0000 L CNN
F 1 "R" H 3670 2655 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 3530 2700 50  0001 C CNN
F 3 "~" H 3600 2700 50  0001 C CNN
	1    3600 2700
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Male J1
U 1 1 60A7966C
P 3800 3700
F 0 "J1" V 3954 3412 50  0000 R CNN
F 1 "RTC Module" V 3863 3412 50  0000 R CNN
F 2 "Connector_PinSocket_2.00mm:PinSocket_1x04_P2.00mm_Vertical" H 3800 3700 50  0001 C CNN
F 3 "~" H 3800 3700 50  0001 C CNN
	1    3800 3700
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR012
U 1 1 60A64FA5
P 10850 850
F 0 "#PWR012" H 10850 600 50  0001 C CNN
F 1 "GND" H 10855 677 50  0000 C CNN
F 2 "" H 10850 850 50  0001 C CNN
F 3 "" H 10850 850 50  0001 C CNN
	1    10850 850 
	-1   0    0    1   
$EndComp
$Comp
L power:+5V #PWR06
U 1 1 60A7F034
P 3800 3200
F 0 "#PWR06" H 3800 3050 50  0001 C CNN
F 1 "+5V" H 3815 3373 50  0000 C CNN
F 2 "" H 3800 3200 50  0001 C CNN
F 3 "" H 3800 3200 50  0001 C CNN
	1    3800 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 2600 5000 2800
Wire Wire Line
	5000 2800 5000 3150
Connection ~ 5000 2800
Wire Wire Line
	5300 2500 5300 2800
Connection ~ 5300 2800
Wire Wire Line
	5300 2800 5300 3150
$Comp
L power:+5V #PWR09
U 1 1 60A890F7
P 5400 1800
F 0 "#PWR09" H 5400 1650 50  0001 C CNN
F 1 "+5V" V 5415 1973 50  0000 C CNN
F 2 "" H 5400 1800 50  0001 C CNN
F 3 "" H 5400 1800 50  0001 C CNN
	1    5400 1800
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR08
U 1 1 60A89C99
P 5400 1700
F 0 "#PWR08" H 5400 1550 50  0001 C CNN
F 1 "+5V" V 5415 1873 50  0000 C CNN
F 2 "" H 5400 1700 50  0001 C CNN
F 3 "" H 5400 1700 50  0001 C CNN
	1    5400 1700
	0    1    1    0   
$EndComp
Wire Wire Line
	4500 2500 5300 2500
Wire Wire Line
	3900 2600 3900 3500
Wire Wire Line
	3800 2600 3900 2600
Wire Wire Line
	4000 2550 4000 3500
Wire Wire Line
	3700 2550 4000 2550
$Comp
L MCU_Microchip_ATmega:ATmega328P-PU U1
U 1 1 60A6D278
P 3900 1700
F 0 "U1" V 3119 1700 50  0000 C CNN
F 1 "ATmega328P-PU" V 3210 1700 50  0000 C CNN
F 2 "Package_DIP:DIP-28_W7.62mm" H 3900 1700 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328_P%20AVR%20MCU%20with%20picoPower%20Technology%20Data%20Sheet%2040001984A.pdf" H 3900 1700 50  0001 C CNN
	1    3900 1700
	0    1    1    0   
$EndComp
$Comp
L Connector:Conn_01x05_Male J2
U 1 1 60A9F18C
P 6100 2000
F 0 "J2" H 6072 1932 50  0000 R CNN
F 1 "7Seg-Display" H 6072 2023 50  0000 R CNN
F 2 "Connector_PinSocket_2.00mm:PinSocket_1x05_P2.00mm_Vertical" H 6100 2000 50  0001 C CNN
F 3 "~" H 6100 2000 50  0001 C CNN
	1    6100 2000
	0    1    1    0   
$EndComp
Wire Wire Line
	4700 2450 6100 2450
Wire Wire Line
	6100 2450 6100 2200
Wire Wire Line
	4900 2400 6200 2400
Wire Wire Line
	6200 2400 6200 2200
Wire Wire Line
	6300 2350 6300 2200
Wire Wire Line
	4500 2300 4500 2500
Wire Wire Line
	4400 2300 4400 2600
Wire Wire Line
	3800 2300 3800 2600
Wire Wire Line
	3700 2300 3700 2550
Wire Wire Line
	3600 2300 3600 2550
Wire Wire Line
	4700 2300 4700 2450
$Comp
L power:GND #PWR01
U 1 1 60A87430
P 2400 1700
F 0 "#PWR01" H 2400 1450 50  0001 C CNN
F 1 "GND" H 2405 1527 50  0000 C CNN
F 2 "" H 2400 1700 50  0001 C CNN
F 3 "" H 2400 1700 50  0001 C CNN
	1    2400 1700
	0    1    1    0   
$EndComp
Wire Wire Line
	6300 2350 4800 2350
Wire Wire Line
	4800 2350 4800 2300
Wire Wire Line
	4900 2400 4900 2300
$Comp
L power:+5V #PWR014
U 1 1 60AB17C2
P 5900 2200
F 0 "#PWR014" H 5900 2050 50  0001 C CNN
F 1 "+5V" V 5915 2373 50  0000 C CNN
F 2 "" H 5900 2200 50  0001 C CNN
F 3 "" H 5900 2200 50  0001 C CNN
	1    5900 2200
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR015
U 1 1 60AB2787
P 6000 2200
F 0 "#PWR015" H 6000 1950 50  0001 C CNN
F 1 "GND" H 6005 2027 50  0000 C CNN
F 2 "" H 6000 2200 50  0001 C CNN
F 3 "" H 6000 2200 50  0001 C CNN
	1    6000 2200
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0101
U 1 1 60A7C01A
P 3600 2850
F 0 "#PWR0101" H 3600 2700 50  0001 C CNN
F 1 "+5V" V 3615 3023 50  0000 C CNN
F 2 "" H 3600 2850 50  0001 C CNN
F 3 "" H 3600 2850 50  0001 C CNN
	1    3600 2850
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Male J3
U 1 1 60A8537F
P 2000 2000
F 0 "J3" H 1972 1932 50  0000 R CNN
F 1 "GND_IN" H 1972 2023 50  0000 R CNN
F 2 "Connector_PinSocket_2.00mm:PinSocket_1x01_P2.00mm_Vertical" H 2000 2000 50  0001 C CNN
F 3 "~" H 2000 2000 50  0001 C CNN
	1    2000 2000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR010
U 1 1 60A859E3
P 5600 2800
F 0 "#PWR010" H 5600 2550 50  0001 C CNN
F 1 "GND" H 5605 2627 50  0000 C CNN
F 2 "" H 5600 2800 50  0001 C CNN
F 3 "" H 5600 2800 50  0001 C CNN
	1    5600 2800
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x01_Male J4
U 1 1 60A844C4
P 2000 2200
F 0 "J4" H 1972 2132 50  0000 R CNN
F 1 "POWER_IN" H 1972 2223 50  0000 R CNN
F 2 "Connector_PinSocket_2.00mm:PinSocket_1x01_P2.00mm_Vertical" H 2000 2200 50  0001 C CNN
F 3 "~" H 2000 2200 50  0001 C CNN
	1    2000 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 2000 2400 2000
Wire Wire Line
	2400 2000 2400 1700
Connection ~ 2400 1700
Wire Wire Line
	2400 2000 2400 3350
Connection ~ 2400 2000
Wire Wire Line
	3100 2950 3100 3100
Connection ~ 3100 3100
Wire Wire Line
	3100 3100 3100 3150
$Comp
L power:GND #PWR07
U 1 1 60A84ACF
P 4700 2800
F 0 "#PWR07" H 4700 2550 50  0001 C CNN
F 1 "GND" H 4705 2627 50  0000 C CNN
F 2 "" H 4700 2800 50  0001 C CNN
F 3 "" H 4700 2800 50  0001 C CNN
	1    4700 2800
	0    1    1    0   
$EndComp
Wire Wire Line
	5600 2800 5600 3350
Wire Wire Line
	5600 3350 4700 3350
Connection ~ 5600 2800
Wire Wire Line
	3800 3200 3800 3250
Wire Wire Line
	3600 2850 3700 2850
Wire Wire Line
	3700 2850 3700 3250
Wire Wire Line
	3700 3250 3800 3250
Connection ~ 3600 2850
Connection ~ 3800 3250
Wire Wire Line
	3800 3250 3800 3450
Wire Wire Line
	2200 3950 2200 2200
Wire Wire Line
	3750 3950 3750 3800
Wire Wire Line
	3750 3450 3800 3450
Wire Wire Line
	2200 3950 3750 3950
Connection ~ 3800 3450
Wire Wire Line
	3800 3450 3800 3500
Wire Wire Line
	3700 3500 3700 3300
Wire Wire Line
	3700 3300 3350 3300
Wire Wire Line
	3350 3100 3350 3200
$Comp
L power:GND #PWR05
U 1 1 60A7D379
P 3350 3200
F 0 "#PWR05" H 3350 2950 50  0001 C CNN
F 1 "GND" H 3355 3027 50  0000 C CNN
F 2 "" H 3350 3200 50  0001 C CNN
F 3 "" H 3350 3200 50  0001 C CNN
	1    3350 3200
	0    -1   -1   0   
$EndComp
Connection ~ 3350 3200
Wire Wire Line
	3350 3200 3350 3300
Wire Wire Line
	5900 2200 5400 2200
Connection ~ 5400 1800
Wire Wire Line
	5400 1700 5400 1800
Connection ~ 5400 1700
Wire Wire Line
	5400 1700 5400 1550
Wire Wire Line
	5400 1550 6500 1550
Wire Wire Line
	6500 1550 6500 3800
Wire Wire Line
	6500 3800 3750 3800
Connection ~ 3750 3800
Wire Wire Line
	3750 3800 3750 3450
Connection ~ 5900 2200
Wire Wire Line
	5400 1800 5400 2200
$Comp
L Connector:Conn_01x01_Male J5
U 1 1 60ADE407
P 3000 2600
F 0 "J5" V 3154 2512 50  0000 R CNN
F 1 "+" V 3063 2512 50  0000 R CNN
F 2 "Connector_PinSocket_2.00mm:PinSocket_1x01_P2.00mm_Vertical" H 3000 2600 50  0001 C CNN
F 3 "~" H 3000 2600 50  0001 C CNN
	1    3000 2600
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x01_Male J7
U 1 1 60AE983A
P 3100 2600
F 0 "J7" V 3254 2512 50  0000 R CNN
F 1 "+" V 3163 2512 50  0000 R CNN
F 2 "Connector_PinSocket_2.00mm:PinSocket_1x01_P2.00mm_Vertical" H 3100 2600 50  0001 C CNN
F 3 "~" H 3100 2600 50  0001 C CNN
	1    3100 2600
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x01_Male J9
U 1 1 60AE9FFD
P 3200 2600
F 0 "J9" V 3354 2512 50  0000 R CNN
F 1 "+" V 3263 2512 50  0000 R CNN
F 2 "Connector_PinSocket_2.00mm:PinSocket_1x01_P2.00mm_Vertical" H 3200 2600 50  0001 C CNN
F 3 "~" H 3200 2600 50  0001 C CNN
	1    3200 2600
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3200 2300 3200 2400
Wire Wire Line
	3100 2400 3100 2300
Wire Wire Line
	3000 2300 3000 2400
$Comp
L Connector:Conn_01x01_Male J8
U 1 1 60AF0E1F
P 3100 2750
F 0 "J8" V 3162 2794 50  0000 L CNN
F 1 "-" V 3253 2794 50  0000 L CNN
F 2 "Connector_PinSocket_2.00mm:PinSocket_1x01_P2.00mm_Vertical" H 3100 2750 50  0001 C CNN
F 3 "~" H 3100 2750 50  0001 C CNN
	1    3100 2750
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR03
U 1 1 60A95B6D
P 3100 3150
F 0 "#PWR03" H 3100 2900 50  0001 C CNN
F 1 "GND" H 3105 2977 50  0000 C CNN
F 2 "" H 3100 3150 50  0001 C CNN
F 3 "" H 3100 3150 50  0001 C CNN
	1    3100 3150
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D1
U 1 1 60A96804
P 2700 2750
F 0 "D1" H 2693 2967 50  0000 C CNN
F 1 "LED" H 2693 2876 50  0000 C CNN
F 2 "LED_THT:LED_D3.0mm" H 2700 2750 50  0001 C CNN
F 3 "~" H 2700 2750 50  0001 C CNN
	1    2700 2750
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R2
U 1 1 60A9C9F2
P 2700 2450
F 0 "R2" H 2770 2496 50  0000 L CNN
F 1 "R" H 2770 2405 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 2630 2450 50  0001 C CNN
F 3 "~" H 2700 2450 50  0001 C CNN
	1    2700 2450
	1    0    0    -1  
$EndComp
Connection ~ 4700 2800
Wire Wire Line
	4400 2600 5000 2600
Wire Wire Line
	4700 3350 4700 2800
$Comp
L Device:Crystal Y1
U 1 1 60A70F29
P 5150 3150
F 0 "Y1" H 5150 2882 50  0000 C CNN
F 1 "Crystal" H 5150 2973 50  0000 C CNN
F 2 "Crystal:Crystal_HC52-6mm_Vertical" H 5150 3150 50  0001 C CNN
F 3 "~" H 5150 3150 50  0001 C CNN
	1    5150 3150
	-1   0    0    1   
$EndComp
Wire Wire Line
	3100 3100 3350 3100
Wire Wire Line
	2850 3100 3100 3100
Wire Wire Line
	2850 3100 2850 3350
Wire Wire Line
	2700 2900 2700 3350
Wire Wire Line
	2850 3350 2700 3350
Connection ~ 2700 3350
Wire Wire Line
	2400 3350 2700 3350
$Comp
L power:GND #PWR013
U 1 1 60A9E3BD
P 2700 3350
F 0 "#PWR013" H 2700 3100 50  0001 C CNN
F 1 "GND" H 2705 3177 50  0000 C CNN
F 2 "" H 2700 3350 50  0001 C CNN
F 3 "" H 2700 3350 50  0001 C CNN
	1    2700 3350
	1    0    0    -1  
$EndComp
$EndSCHEMATC
