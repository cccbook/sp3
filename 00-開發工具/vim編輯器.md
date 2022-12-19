# vim 編輯器使用

## 基本使用

* http://kevinchen.synology.me/TechnicalDocuments/About_Linux/Fread_eazyvim.html

Fred Chien: 

Vim 其實沒這麼難呀，新手只要學會幾招，就基本上可以丟掉其他 IDE 了。一開始就把 Vim 講太難，根本只是高手耍帥而已，初學者可以不用鳥呀。

1. 只要沒事就按 Esc，讓他離開編輯模式，就可以輸入指令。若想進入編輯模式就按一下 i ，就可以開始編輯及插入文字。
2. 然後只要學會在非編輯模式下輸入 :w 與 :q 再加上 Enter，就會存檔和離開程式。
3. yy 和 p 超好用，講明白了就是複製一行與貼上，剪下一行則是用 cc。
    * 複製三行用 3yy
4. 像要插入一行空白行，並直接進入編輯模式在新的一行開始編輯，就用 o。
5. 刪除一行用 dd。 (刪除三行用 3dd)
6. 跳到指定第幾行就這樣用 :100 （到第一百行）
7. 尋找字串用 / ，如： /fred。取代所有字串用 :%s/fred/pig/g 。
8. u 要配合 Ctrl+r 一起用，一個是復原，一個是取消復原。不過 Ctrl+r 沒痛過的話，比較難記得，要經歷過很多次的誤按 u ，才會痛定思痛把這個組合鍵背起來。XD

基本上，這樣就夠了，等用熟了再來學更多吧。（什麼 Shift+V 之類的東西） 喔，對了，注意指令的大小寫。請確定 Caps Lock 的燈是滅的再來按指令。


## 剪貼 (Cut and paste:)

開頭按 v, 結尾按 d (剪下) 或 y (複製)

最後按 p 貼上！

1. Position the cursor where you want to begin cutting.
2. Press v to select characters (or uppercase V to select whole lines).
3. Move the cursor to the end of what you want to cut.
4. Press d to cut (or y to copy).
5. Move to where you would like to paste.
6. Press P to paste before the cursor, or p to paste after.
