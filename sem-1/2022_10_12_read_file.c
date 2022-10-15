#include <stdio.h>
#include <ctype.h>

void printFileContent(char file[]);
void copyToAnotherFile(char fin[], char fout[]);
void countVowel(char fin[]);
void countConsonant(char fin[]);
void countAlphabet(char fin[]);
void printFromFinalNCharacters(char fin[], int offset); // use of fseek()

int main()
{

  // printFileContent("abc");
  // printFileContent("xyz");
  // printFileContent("mno");
  // copyToAnotherFile("abc", "xyz");
  // countVowel("mno");
  // countConsonant("mno");
  // countAlphabet("mno");
  printFromFinalNCharacters("mno", 26);

  return 0;
}

void printFileContent(char file[])
{
  FILE *fl;
  char ch;
  fl = fopen(file, "r");
  ch = fgetc(fl);
  printf("File content \"%s\" -> \t", file);
  while (ch != EOF)
  {
    printf("%c", ch);
    ch = fgetc(fl);
  }
  printf("\n");
  fclose(fl);
}

void copyToAnotherFile(char fin[], char fout[])
{
  FILE *fl1, *fl2;
  char ch;
  fl1 = fopen(fin, "r");
  fl2 = fopen(fout, "w");
  ch = fgetc(fl1);
  while (ch != EOF)
  {
    fputc(ch, fl2);
    ch = fgetc(fl1);
  }
  printf("File copied successfully\n");
  fclose(fl1);
  fclose(fl2);
}

void countVowel(char fin[])
{
  FILE *fl;
  char ch;
  int count = 0;
  fl = fopen(fin, "r");
  while (ch != EOF)
  {
    ch = tolower(fgetc(fl));
    count += (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') ? 1 : 0;
  }
  fclose(fl);
  printf("Number of Vowels in the file \" %s \"-> \t %d \n", fin, count);
}

void countConsonant(char fin[])
{
  FILE *fl;
  char ch;
  int count = 0;
  fl = fopen(fin, "r");
  while (ch != EOF)
  {
    ch = tolower(fgetc(fl));
    count += (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') && (ch >= 'a' && ch <= 'z')) ? 1 : 0;
  }
  fclose(fl);
  printf("Number of Consonant in the file \" %s \"-> \t %d \n", fin, count);
}

void countAlphabet(char fin[])
{
  FILE *fl;
  char ch;
  int count = 0;
  fl = fopen(fin, "r");
  while (ch != EOF)
  {
    ch = tolower(fgetc(fl));
    count += (ch >= 'a' && ch <= 'z') ? 1 : 0;
  }
  fclose(fl);
  printf("Number of Alphabets in the file \" %s \"-> \t %d \n", fin, count);
}

void printFromFinalNCharacters(char fin[], int offset)
{
  FILE *fl;
  char ch;
  fl = fopen(fin, "r");
  fseek(fl, -(offset), 2);
  printf(" \"%s\" -> \t", fin);
  ch = fgetc(fl);

  while (ch != EOF)
  {
    printf("%c", ch);
    ch = fgetc(fl);
  }
  printf("\n");
  fclose(fl);
}