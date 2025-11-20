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

  Plik z danymi: ~/.todo_db.txt (każdy wiersz: id,title,done)
*/

void get_last_id(const char *file_name) {
  FILE *file = fopen(file_name, "r");

  if (!file) {
    printf("Nie moge otworzyc pliku");
  }

  printf("Dane\n");

  char *line;
  char *s_string = "Todo_id";
  char *result;

  while (fgets(line, sizeof(line), file)) {
    // TODO: jak zdobyc id?
    //
  }

  fclose(file);
}

void todo_add(const char *task_title, const char *file_name) {
  // adding to file
  FILE *file;
  FILE *file_exist = fopen(file_name, "r");

  if (!file_exist) {
    printf("Brak pliku");
  }

  // additional data
  int todo_id = 1;

  time_t now;
  time(&now);
  char *date_time = ctime(&now);

  char *message = "Todo_id: %d\nTask Name: %s\nTask Time: %sDone: false\n";

  //  check file exist
  if (file_exist == NULL) {
    // create and write
    file = fopen(file_name, "w");
    fprintf(file, message, todo_id, task_title, date_time);
    printf("Plik zostal utworzony pod nazwa %s \n", file_name);
  } else {
    // update file
    file = fopen(file_name, "a");
    fprintf(file, message, todo_id, task_title, date_time);
    printf("Zadanie '%s' zostalo dodane do pliku %s \n", task_title, file_name);
  }

  fclose(file);
}

void todo_read(const char *file_name) {
  // return data from file

  FILE *file;
  file = fopen(file_name, "r");

  char ret_data[100];
  int i = 0;

  printf("Twoje zadania: \n");

  while (fgets(ret_data, 100, file)) {
    // i++;
    // printf(ret_data[i]);

    printf("%s", ret_data);
  }

  fclose(file);
}

int main() {

  const char *file_name = "todo_db.txt";

  // todo_add("Zadanie1", file_name);
  // todo_read();

  get_last_id(file_name);

  return 0;
}
