from pathlib import Path

from PIL import Image, ImageDraw, ImageFont


TEXT = "温度:湿度:気圧"
FONT_PATH = Path(__file__).with_name("DotGothic16-Regular.ttf")
OUTPUT_PATH = Path(__file__).with_name("title.png")
FONT_SIZE = 16


def create_bitmap() -> Path:
    font = ImageFont.truetype(FONT_PATH, FONT_SIZE)
    left, top, right, bottom = font.getbbox(TEXT)
    image = Image.new("1", (right - left, bottom - top), 0)
    draw = ImageDraw.Draw(image)
    draw.text((-left, -top), TEXT, font=font, fill=1)
    image.save(OUTPUT_PATH)
    return OUTPUT_PATH


if __name__ == "__main__":
    output = create_bitmap()
    with Image.open(output) as image:
        print(f"保存しました: {output}")
        print(f"サイズ: {image.size}, モード: {image.mode}")
