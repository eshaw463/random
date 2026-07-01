import tkinter as tk
from tkinter import simpledialog
import time
import pyautogui

def run_prog():
    ROOT = tk.Tk()
    ROOT.attributes('-topmost', True)
    ROOT.withdraw()

    done = 0

    while done == 0:
        # input
        USER_INP = simpledialog.askstring(title="bin racer", prompt="number? type exit to quit")

        if USER_INP == "exit":
            exit()

        if USER_INP is not None:
            num_to_macro = str(bin(int(str(USER_INP)))[2:])[::-1] #str->int->bin[w/o header]->str->reversed

        # do stuff w/ input
        macro(num_to_macro)
        
   
# 128 ~ x=1044, y=1800
# 64 ~ x=1272, y=1800
# 32 ~ x=1482
# 16 ~ x=1712
# 8 ~ x=1937
# 4 ~ x=2164
# 2 ~ x=2372
# 1 ~ x=2610
# pyautogui.click(x=1, y=1)


def macro(inp):
    for i in range(len(inp)):
        if inp[i] == "0":
            continue
        elif inp[i] == "1":
            if i == 0:
                pyautogui.click(x=2470, y=1700)
                time.sleep(0.1)
            elif i == 1:
                pyautogui.click(x=2270, y=1700)
                time.sleep(0.1)
            elif i == 2:
                pyautogui.click(x=2065, y=1700)
                time.sleep(0.1)
            elif i == 3:
                pyautogui.click(x=1859, y=1700)
                time.sleep(0.1)
            elif i == 4:
                pyautogui.click(x=1645, y=1700)
                time.sleep(0.1)
            elif i == 5:
                pyautogui.click(x=1450, y=1700)
                time.sleep(0.1)
            elif i == 6:
                pyautogui.click(x=1235, y=1700)
                time.sleep(0.1)
            elif i == 7:
                pyautogui.click(x=1040, y=1700)
                time.sleep(0.1)
    pyautogui.click(x=1918, y=1928)
    time.sleep(0.1)



if __name__ == "__main__":
    run_prog()  