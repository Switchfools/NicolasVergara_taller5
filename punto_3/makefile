caos.pdf : caos.py caos.txt
	python3 caos.py
caos.txt : caos.x
	./caos.x>caos.txt
caos.x :caos.cpp
	c++ caos.cpp -o caos.x