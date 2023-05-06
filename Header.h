#include <AccelStepper.h>
#include <vector_type.h>
#include <Math.h>

#define KANAN 1
#define KIRI 0
#define BELAKANG -1
#define DEPAN 1

#define STEPS_PER_ROTATION 800

String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;

  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }

  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}
