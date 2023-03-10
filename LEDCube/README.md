<a name="readme-top"></a>

<!-- ABOUT THE PROJECT -->

# 1. プロジェクトについて

LED 8 個を使った 2x2x2 の LED Cube を作成するプロジェクトです。  
Arduino IDE を使用して、スケッチ例 01.Basics - Blink を元に、LED のプログラムを作成しています。

<img src="./img/IMG_3631.JPEG" width="480">

3x3x3 の作り方もあります。

<img src="./img/IMG_3653.JPEG" width="480">

<p align="right">(<a href="#readme-top">back to top</a>)</p>

# 2. Arduino IDE

- Arduino IDE [ツール]の指定  
  ボード：Arduino Nano  
  プロセッサ：ATmega328P (Old Bootloader)

- スケッチ例  
  01.Basics - Blink

<p align="right">(<a href="#readme-top">back to top</a>)</p>

# 3. 配線図

## 3.1. 2x2x2 LED Cube

| Nano | LED     |
| ---- | ------- |
| A3   | Layer1  |
| A4   | Layer2  |
|      |         |
| D3   | Column1 |
| D4   | Column2 |
| D5   | Column3 |
| D6   | Column4 |

<img src="./img/PinConnections.jpg" width="480">

<p align="right">(<a href="#readme-top">back to top</a>)</p>

# 4. 2x2x2 LED Cube の作り方

## 4.1. Layer の作成

- LED Cube 作成プレート に LED のアノード(+)が右になるように LED を挿します。

<img src="./img/IMG_3646.JPEG" width="480">

- 前の LED のアノードを後ろへ、後ろの LED は前へ倒してはんだ付けします。
- すずめっき線 3cm を横にはんだ付けします。
- カソード(-)を L 字型に曲げます。L 字の角は LED の少し外側で曲げます。
- これを 2 つ作ります。

<img src="./img/IMG_3627.JPEG" width="480">

## 4.2. LED Cube の作成

- 赤の 2.5cm 部分をはんだ付けするため、すずめっき線 3cm を 4 つ作成します。
- すずめっき線を使って 2 つの Layer のカソードを 4 箇所はんだ付けし Cube にします。
- Layer1 の横線からユニバーサル基盤までの長さの線を作成します。
- Layer1 の横線にはんだ付けします。Layer2 も同じです。

<img src="./img/IMG_3628.JPEG" width="480">

## 4.3. ユニバーサル基盤への配線

- Nano 用のヘッダーソケットをはんだ付けします。
- 角の 4 つと、線をつなげる 6 箇所をはんだ付けすれば OK です。
- 配線図の通りにはんだ付けします。
- A3 と A4 の間には 100 オームの抵抗をいれます。

<img src="./img/IMG_3632.JPEG" width="480">

## 4.4. プログラムの書き込み

- すぐにお試ししたい場合には LEDCube.ino を書込します。

# 5. 3x3x3 LED Cube の作り方

## 5.1. Layer の作成

- LED Cube 作成プレート に LED のアノード(+)が右になるように LED を挿します。

<img src="./img/IMG_3650.JPEG" width="480">

- アノード(+)を右へ倒します。
- すずめっき線 5cm を、縦に 3 つ、横に 1 つはんだ付けします。
- カソード(-)を L 字型に曲げます。L 字の角は LED の少し外側で曲げます。
- これを 3 つ作ります。

<img src="./img/IMG_3652.JPEG" width="480">

## 5.2. LED Cube の作成

- 縦 5cm 部分をはんだ付けするため、すずめっき線 7cm を 9 つ作成します。
- すずめっき線を使って 3 つの Layer のカソード 9 箇所をはんだ付けし Cube にします。
- Layer1,2,3 の横線からユニバーサル基盤までの長さの線を作成します。
- Layer1,2,3 の横線にはんだ付けします。

<img src="./img/IMG_3653.JPEG" width="480">
<img src="./img/IMG_3654.JPEG" width="480">

## 5.3. ユニバーサル基盤への配線

- Nano 用のヘッダーソケットをはんだ付けします。
- 角の 4 つと、Layer,Column をつなげる箇所をはんだ付けすれば OK です。
- Layer は 100 オームの抵抗を入れて A3,4,5 にはんだ付けします。
- Column は A2 ～ A10 にはんだ付けします。
- つなげる先はお好みに合わせてください。

<img src="./img/IMG_3655.JPEG" width="480">

## 5.4. プログラムの書き込み

- LEDCube.ino を参考に作成して書込します。

# 6. 参考

- [Arduino IDE](https://www.arduino.cc/en/software)
- [Arduino Nano](https://store-usa.arduino.cc/products/arduino-nano/)
