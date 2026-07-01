import pyautogui
import time

print("move mouse to target")
time.sleep(3)
x, y = pyautogui.position()
print(f"X={x}, Y={y}")