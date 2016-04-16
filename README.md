


If you have installed BCM-2835, please do like this!

$git clone https://github.com/hengshuangliu/MFRC522.git

$cd MFRC522

$gcc -o read.exe read.c MFRC522.* -l bcm2835

$sudo ./read.exe
