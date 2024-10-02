#include <stdio.h>
#include <string.h>

#define NAME_MAX 100
#define NUM_MAX 100
#define INFO_MAX 101

#define SUCCESSFUL_REGISTRATION "Contato cadastrado com sucesso!"
#define INDEX_ERROR "Índice digitado não existe [1, 100]!"
#define PHONE_ERROR "Telefone não tem 10 ou 11 dígitos! Favor digite novamente."
#define EMPTY_LIST "Agenda vazia!"
#define REMOVED_CONTACT "Contato removido com sucesso!"
#define EMPTY_INDEX "Índice digitado está vazio!"
#define NULL_CONTACT "Contato digitado não existe!"
#define END_CHOOSE "Escolha valores entre 0 e 5!"
#define END "Tchau!"

struct PersonalInfo {
  char name[NAME_MAX];
  char phoneNumber[NUM_MAX];
};

//==== Funções usadas posteriormente

int Input() {
  int num;
  
  scanf("%d", &num);
  
  return num;
}

void CharInput(char contactName[NAME_MAX]) {
  scanf("%s", contactName);
  
  return;
}

int CheckingIndex(struct PersonalInfo info[INFO_MAX], int index) {
  if (index < 1 || index > 100) {
    puts(INDEX_ERROR);
    return 1;
  }
  
  return 0;
}

void SettingNamePhone(struct PersonalInfo info[INFO_MAX], int index) {
  scanf("%s", info[index].name);
  scanf("%s", info[index].phoneNumber);
  
  return;
}

void CheckingPhone(struct PersonalInfo info[INFO_MAX], int index) {
  while (strlen(info[index].phoneNumber) != 10 && strlen(info[index].phoneNumber) != 11) {
    puts(PHONE_ERROR);
    scanf("%s", info[index].phoneNumber);
  }
  puts(SUCCESSFUL_REGISTRATION);
  
  return;
}

void PrintingSingleContact(struct PersonalInfo info[INFO_MAX], int contactIndex) {
  printf("Contato[%d]- Nome:%s Tel:%s\n", contactIndex, info[contactIndex].name, info[contactIndex].phoneNumber);
  
  return;
}

void PrintingContactList(struct PersonalInfo info[INFO_MAX]) {
  int contactIndex;
  
  for (contactIndex = 1; contactIndex < INFO_MAX; contactIndex++) {
    if (strlen(info[contactIndex].phoneNumber) == 10 || strlen(info[contactIndex].phoneNumber) == 11) {
      PrintingSingleContact(info, contactIndex);
    }
  }
  
  return;
}

int CheckingList(struct PersonalInfo info[INFO_MAX]) {
  int index, count;
  
  count = 0;
  for (index = 1; index < INFO_MAX; index++) {
    if (strlen(info[index].name) == 0 && strlen(info[index].phoneNumber) == 0) {
      count++;
    }
    
    if (index == INFO_MAX - 1) {
      if (count == INFO_MAX - 1) {
        puts(EMPTY_LIST);
        return 1;
      }
    }
  }
  
  return 0;
}


void CheckingContactEmptiness(struct PersonalInfo info[INFO_MAX], int contactIndex) {
  if (strlen(info[contactIndex].phoneNumber) == 10 || strlen(info[contactIndex].phoneNumber) == 11) {
    PrintingSingleContact(info, contactIndex);
  } else if (strlen(info[contactIndex].phoneNumber) != 10 && strlen(info[contactIndex].phoneNumber) != 11) {
    puts(EMPTY_INDEX); // NULL_CONTACT
  }
  
  return;
}

int CheckingIndexEmptiness(struct PersonalInfo info[INFO_MAX], int index) {
  if (strlen(info[index].name) == 0 && strlen(info[index].phoneNumber) == 0) {
    puts(EMPTY_INDEX);
    return 1;
  }
  return 0;
}

void PrintingDeletingContactList(struct PersonalInfo info[INFO_MAX]) {
  int contactIndex;
  
  for (contactIndex = 1; contactIndex < INFO_MAX; contactIndex++) {
    if (strlen(info[contactIndex].phoneNumber) == 10 || strlen(info[contactIndex].phoneNumber) == 11) {
      PrintingSingleContact(info, contactIndex);
    }
  }
  
  return;
}

int CheckingContactName(struct PersonalInfo info[INFO_MAX], char contactName[NAME_MAX]) {
  int index, count, mark;
  
  mark = 0;
  count = 0;
  for (index = 1; index < INFO_MAX; index++) {
    if (strcmp(info[index].name, contactName) == 0) {
      count++;
      mark = index;
    }
    
    if (index == INFO_MAX - 1) {
      if (count == 0) {
        puts(NULL_CONTACT);
      }
    }
  }
  return mark;
}


void Cleaner(struct PersonalInfo info[INFO_MAX], int contactIndex) {
  char cleaner[1] = {0};
  
  strcpy(info[contactIndex].name, cleaner);
  strcpy(info[contactIndex].phoneNumber, cleaner);
  
  puts(REMOVED_CONTACT);
  
  return;
}


//=============================================================================


//=== 1 - Cadastra nome e número de telefone.
void GetNamePhone(struct PersonalInfo info[INFO_MAX]) {
  int index;
  
  index = Input();
  
  if (CheckingIndex(info, index) == 1) {
    ;
  } else if (CheckingIndex(info, index) == 0) {
    SettingNamePhone(info, index);
    CheckingPhone(info, index);
  }
  
  return;
}

//=== 2 - Exibidor da lista de contatos inteira.
void PrintContactList(struct PersonalInfo info[INFO_MAX]) {
  
  if (CheckingList(info) == 1) {
    ;
  } else if (CheckingList(info) == 0) {
    PrintingContactList(info);
  }
  
  return;
}

//=== 3 - Exibidor de um único contato.
void ShowingSingleContact(struct PersonalInfo info[INFO_MAX]) {
  int contactIndex;
  
  if (CheckingList(info) == 1) {
    ;
  } else if (CheckingList(info) == 0) {
    contactIndex = Input();
    if (CheckingIndex(info, contactIndex) == 1) {
      ;
    } else if (CheckingIndex(info, contactIndex) == 0) {
      CheckingContactEmptiness(info, contactIndex);
      return;
    }
  }
  
  return;
}

//=== 4 - Deleção através do índice do contato.
void DeletingContactByPhone(struct PersonalInfo info[INFO_MAX]) {
  int contactIndex;
  
  contactIndex = Input();
  
  if (CheckingIndex(info, contactIndex) == 1) {
    ;
  } else if (CheckingIndexEmptiness(info, contactIndex) == 1) {
    ;
  } else if (CheckingIndexEmptiness(info, contactIndex) == 0) {
    Cleaner(info, contactIndex);
    PrintingDeletingContactList(info);
  }
  
  return;
}

//=== 5 - Deleção através do nome.
void DeletingContactByName(struct PersonalInfo info[INFO_MAX]) {
  char contactName[NAME_MAX];
  int index;
  
  CharInput(contactName);
  
  index = CheckingContactName(info, contactName);
  
  if (index > 0 && index < 101) {
   Cleaner(info, index);
   PrintingDeletingContactList(info);
  }
  
  return;
}

//=== Saída da aplicação.
void End() {
  puts(END);
  return;
}



//=== Menu de opções.
int main() {
  struct PersonalInfo info[INFO_MAX] = {0};
  int chooseOption, i, j;
  
  do {
    chooseOption = Input();
    
    if (chooseOption < 0 || chooseOption > 5) {
      puts(END_CHOOSE);
      continue;
    }
    
    switch (chooseOption) {
      case 1:
        GetNamePhone(info);
        break;
      case 2:
        PrintContactList(info);
        break;
      case 3:
        ShowingSingleContact(info);
        break;
      case 4:
        DeletingContactByPhone(info);
        break;
      case 5:
        DeletingContactByName(info);
        break;
      case 0:
        End();
        return 0;
    }
  } while (chooseOption != 0);
  
  return 0;
}