#include <stdio.h>
#include <string.h>
#include <time.h>

// prosta todo lista z zapisem do pliku

// TODO:
//
//  - dodac pobieranie danych z klawiatury
//  - dodac Id do kazdego zadania
//  - dodac usuwanie zadan
//

/*
Funkcje:
  todo add "Kup mleko" — dodaje nowe zadanie
  todo list — pokazuje listę zadań z id i statusem
  todo done <id> — oznacza zadanie jako wykonane
  todo rm <id> — usuwa zadanie
  todo clear — usuwa wszystkie zadania

  Plik z danymi: ~/.todo_db.csv (każdy wiersz: id,title,done)
*/

FILE *file;
const char *file_name = "todo_db.txt";

void todo_add(const char *task_title) {
  // adding to file
  FILE *file_exist = fopen(file_name, "r");

  // additional data
  time_t now;
  time(&now);
  char *date_time = ctime(&now);

  // FIXME: add and check id in file

  //  check file exist
  if (file_exist == NULL) {
    // create and write
    file = fopen(file_name, "w");
    fprintf(file, "Task Name: %s\nTask Time: %s\n", task_title, date_time);
    printf("Plik zostal utworzony pod nazwa %s \n", file_name);
  } else {
    // update file
    file = fopen(file_name, "a");
    fprintf(file, "Task Name: %s\nTask Time: %s\n", task_title, date_time);
    printf("Zadanie '%s' zostalo dodane do pliku %s \n", task_title, file_name);
  }

  fclose(file);
}

void todo_read() {
  // return data from file
  file = fopen("todo_db.txt", "r");

  char ret_data[100];

  printf("Twoje zadania: \n");

  while (fgets(ret_data, 100, file)) {
    printf("%s", ret_data);
  }

  fclose(file);
}

int main() {

  todo_add("Zadanie1");
  todo_read();

  return 0;
}
