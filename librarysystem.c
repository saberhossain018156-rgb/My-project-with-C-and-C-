#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct Book{
    int id;
    char title[50];
    char auther[50];
    int isIssued;
};

void addbook(){
    struct Book newbook;
    FILE *file = fopen("libary.dat", "ad");
    printf("Enter the book ID:");
    scanf("%d",&newbook.id);
    getchar();
    printf("Enter book title:");
    fgets(newbook.title,50,stdin);
    printf("Enter the auther name:");
    fgets(newbook.auther,50,stdin);
    newbook.isIssued = 0;

    fwrite(&newbook,sizeof(struct Book),1 , file);
    fclose(file);

    printf("BOOK ADDED");
}

void displaybook(){
    struct Book book;
    FILE *file = fopen("libaray.dat","rd");

    while(fread(&book,sizeof(struct Book),1,file)){
        printf("ID:%d\nTitle:%s\nAuthor:%s\nStatus:%s\n\n",book.id, book.title, book.auther, book.isIssued ? "Issurd" : "Available");
    }

    fclose(file);
}

void issueBook (){
    struct Book book;
    int bookID ,found = 0;
    FILE *file = fopen("library.dat", "rb+");

    printf("Enter Book id issue :");
    scanf("%d",&bookID);

    while(fread(&book,sizeof(struct Book) ,1, file)){
        if(book.id==bookID && book.isIssued == 0){
            book.isIssued = 1;
            fseek(file,sizeof(struct Book),SEEK_CUR);
            fwrite(&book,sizeof(struct Book),1 , file);
            printf("Book issued succefully added\n");
            found = 1;
            break;
        }
    }

    if(!found){
        printf("Book not found or already issued\n");
    }

    fclose(file);
}

void returnBook(){
    struct Book book;
    int bookID, found = 0;
    FILE *file = fopen("library.dat", "rb+");

    printf("Enter book ID return:");
    scanf("%d",&bookID);

    while(fread(&book,sizeof(struct Book) ,1, file)){
        if(book.id==bookID && book.isIssued == 1){
            book.isIssued = 0;
            fseek(file,sizeof(struct Book),SEEK_CUR);
            fwrite(&book,sizeof(struct Book),1 , file);
            printf("Book return succefully!\n");
            found = 1;
            break;
        }
    }
    if(!found){
    printf("Invalid book issued or book is not issued.\n");
    }

    fclose(file);

}

int main(){
    int number;
    while(1){
        printf("Mune\n");
        printf("1.ADD BOOK\n");
        printf("2.DISPLAY ALL BOOK\n");
        printf("3.ISSUE BOOK\n");
        printf("4.RETURN BOOK\n");
        printf("5.EXIT\n");

        printf("Enter your chose:");
        scanf("%d",&number);

        switch(number){
            case 1: addbook();
            break;  
            case 2: displaybook();
            break;  
            case 3: issueBook();
            break;
            case 4: returnBook();
            break;
            case 5: exit(0);
            break;
            default:printf("Invalie Choice!\n");   
        }
    }

    return 0;
}