#include <stdio.h>
#include <string.h>

struct students
{
    char name[10];
    int weight;
    int height;

};

void analyzing()
{
  FILE *file = fopen("students.txt", "r");
  char data[27];
  int height, maxHeight = 0, weight, maxWeight = 0;
  struct students theHighest;
  struct students theHeaviest;
  for(int i = 0; i < 10; i++){
      fgets(data, 27, file);
      height = ((int)data[16] - 48) * 100 + ((int)data[17] - 48)* 10 + (int)data[18] - 48;
      weight = ((int)data[20] - 48) * 10 + ((int)data[21] - 48);
      if(height > maxHeight){
          maxHeight = height;
          for(int j = 0; j < 9; j++)
              theHighest.name[j] = data[j];
          theHighest.name[9] = NULL;
      }
      if(weight > maxWeight){
          maxWeight = weight;
          for(int j = 0; j < 9; j++)
              theHeaviest.name[j] = data[j];
          theHeaviest.name[9] = NULL;
      }
  }
  fclose(file);
  printf("The highest student - %s\t\t%i\n", theHighest.name, maxHeight);
  printf("The heaviest student - %s\t%i\n", theHeaviest.name, maxWeight);
}
int main() {
    analyzing();
    return 0;
}