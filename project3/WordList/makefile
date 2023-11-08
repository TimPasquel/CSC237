COMPILER  = g++

DEBUG  = -g 

EXE  = app

HDRS  = WordData.h\
	WordDataList.h\
	WordList.h\
	WordCList.h\
        WordSTLSeq.h\


OBJS  = WordData.o\
	WordDataList.o\
	WordCList.o\
        WordSTLSeq.o\
	app.o\

SRC  = 	WordData.cpp\
	WordDataList.cpp\
	WordCList.cpp\
        WordSTLSeq.cpp\
	app.cpp\


##########################################################################
$(EXE): $(OBJS) $(HDRS) $(SRC)
	$(COMPILER) -o $(EXE) $(OBJS) $(DEBUG)

WordData.o:  WordData.cpp WordData.h 
	$(COMPILER) -c WordData.cpp $(DEBUG)

WordDataList.o:  WordData.h WordDataList.cpp WordDataList.h WordList.h 
	$(COMPILER) -c WordDataList.cpp $(DEBUG)

WordCList.o: WordData.h WordCList.cpp WordCList.h WordList.h
	$(COMPILER) -c WordCList.cpp $(DEBUG)

WordSTLSeq.o: WordData.h WordSTLSeq.cpp WordSTLSeq.h WordList.h
	$(COMPILER) -c WordSTLSeq.cpp $(DEBUG)

app.o:  WordDataList.h WordList.h app.cpp 
	$(COMPILER) -c app.cpp $(DEBUG)

clean:
	del *.o $(EXE)
