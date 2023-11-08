// ExecLocal.cpp
// Batch Processor for Running Project 3 Multiple Times
// The input file name is passed in.

//#include <process.h>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <cwait>
#include <cstring>
#include <iostream>

using namespace std;

int main(int argc,char **argv)
{int termstat,pid,count;

  // Command line arguments are:
  //              <file name> <Variable value>

  char **CommandArgs;
  // argv[1] is file name; store in local variable
  int numTimes=10;  // atoi(argv[2]);

  for (count=0;count<numTimes;count++) {
    if ((pid=fork())<0) {
      perror("fork");
      exit(-1);
    }
    else if (!pid) { // child process
       //   (we stored that elsewhere)
       cerr << "Trial " << count+1 << endl;
      pid=execl("app","app",argv[1],0);
      cerr << "execl Failed";
    }
    else {// parent just waits; collects child
    wait(&termstat);
    }
  } // for loop
  return(0);
} // main

