SRC		= word-finder
BUILD		= build
BUILD_NUMBER	?= dev
LIB_PATH = /usr/local/lib
#LT = dylib
LT = a

LIBS		= \
			$(LIB_PATH)/libboost_filesystem-mt.$(LT) 	\
			$(LIB_PATH)/libboost_system-mt.$(LT) 		\
			$(LIB_PATH)/libboost_program_options-mt.$(LT)	\
			$(LIB_PATH)/libboost_regex-mt.$(LT)		\
			$(LIB_PATH)/libaspell.dylib 

OBJECTS 	=	

all		:	build/word-finder

$(BUILD)	:
	-mkdir $@

$(BUILD_TEST)		:	$(BUILD)
	-mkdir $@

$(BUILD)/word-finder	:	$(BUILD) $(OBJECTS) $(BUILD)/main.o
	clang++ -g -O1 -o $@ -std=c++11 -D BUILD_NUMBER='"$(BUILD_NUMBER)"' -Xclang "-stdlib=libc++" -lc++ $(SRC)/*.cpp -I /usr/local/include $(LIBS)

ci-build:	dmg

dist	:
	-mkdir dist

dmg:	word-finder-install-0.0.$(BUILD_NUMBER).dmg

word-finder-install-0.0.$(BUILD_NUMBER).dmg : dist $(BUILD)/word-finder dist/README.html
	ln -s /usr/local/bin dist/bin
	cp $(BUILD)/word-finder dist
	hdiutil create tmp.dmg -ov -volname "word finder" -fs HFS+ -srcfolder "dist" 
	hdiutil convert tmp.dmg -format UDZO -o word-finder-install-0.0.$(BUILD_NUMBER).dmg
	-rm tmp.dmg

dist/README.html	:	dist	README.md
	markdown README.md > dist/README.html

clean:
	-rm -rf $(BUILD)/*
	-rm word-finder-install*.dmg
	-rm tmp.dmg
	-rm -rf dist


$(BUILD)/%.o : $(SRC)/%.cpp	$(BUILD)
	clang++ -g -O1 -std=c++11 -Xclang "-stdlib=libc++" -I $(SRC) -I /usr/local/include -c $< -o $@

$(BUILD)/%.o : $(SRC)/%.c	$(BUILD)
	clang -g -O1 -I $(SRC) -I /usr/local/include -c $< -o $@

$(BUILD_TEST)/%.o : $(TEST_SRC)/%.cpp	$(BUILD_TEST)
	clang++ -g -O1 -std=c++11 -Xclang "-stdlib=libc++" -I $(SRC) -I /usr/local/include -D MAKEFILE_BUILD -c $< -o $@


