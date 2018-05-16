# Codebook of team NCTU_Fox

- [latest version PDF](https://drive.google.com/open?id=1BE3YoEIVL1873pOpBCTAezFNkn0LsXfo)

## Build
```bash
make
```

## Environment

- xelatex
	```bash
	sudo apt-get -y install 	texlive \
					texlive-full \
					gedit-latex-plugin \
					texlive-fonts-recommended \
					latex-beamer \
					texpower \
					texlive-pictures \
					texlive-latex-extra \
					texpower-examples \
					imagemagick
	```
- English font: Consolas 
	```bash
	cd ~/Desktop/
	wget https://github.com/kakkoyun/linux.files/raw/master/fonts/Consolas.ttf
	sudo mkdir -p /usr/share/fonts/consolas
	sudo mv Consolas.ttf /usr/share/fonts/consolas/
	sudo chmod 644 /usr/share/fonts/consolas/Consolas.ttf
	cd /usr/share/fonts/consolas
	sudo mkfontscale && sudo mkfontdir && sudo fc-cache -fv
	```
- Chinese font: [思源黑體](https://www.beforafter.org/blog/source-han-sans-font)
	```bash
	cd ~/Desktop/
	wget https://noto-website.storage.googleapis.com/pkgs/NotoSansCJKtc-hinted.zip
	sudo unzip NotoSansCJKtc-hinted.zip -d /usr/share/fonts/Noto\ Sans\ CJK\ TC/
	cd /usr/share/fonts/Noto\ Sans\ CJK\ TC/
	sudo chmod 644 *.otf
	sudo mkfontscale && sudo mkfontdir && sudo fc-cache -fv
	```
