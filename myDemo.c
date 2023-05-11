#include "stdio.h"
#include "AdptArray.h"
#include "book.h"
#include "Person.h"



int main() {
    // book Adapt Array
    PAdptArray bookArr = CreateAdptArray(copy_book, delete_book , print_book);
    pbook b1 = creat_book("Infi1" , 111);
    pbook b2 = creat_book("Infi2" , 112);

    SetAdptArrayAt(bookArr,0 , b1);
    printf("%d\n" , GetAdptArraySize(bookArr)); // should print 1

    SetAdptArrayAt(bookArr,9 , b2);
    printf("%d\n" , GetAdptArraySize(bookArr)); // should print 10

    pbook b3 = creat_book("CS1" , 113);
    SetAdptArrayAt(bookArr , 4 , b3);
    printf("%d\n" , GetAdptArraySize(bookArr)); // should print 10


    pbook b4 = creat_book("CS2" , 114);
    SetAdptArrayAt(bookArr , 0 , b4);
    pbook temp = GetAdptArrayAt(bookArr , 0);
    printf("%d\n" , temp->serial_number); // should print 114 (not 111)



    PrintDB(bookArr);

    DeleteAdptArray(bookArr);
    delete_book(b1);
    delete_book(b2);
    delete_book(b3);
    delete_book(b4);
    delete_book(temp);



    // person Adapt Array

    PAdptArray personArr = CreateAdptArray(copy_person , delete_person , print_person);

    pperson p1 = creat_person("gabriel" , "nibash" , 222);
    pperson p2 = creat_person("keren" , "nibash" , 223);
    pperson p3 = creat_person("dana" , "shapira" , 224);
    pperson p4 = creat_person("boaz" , "ben moshe" , 225);
    pperson p5 = creat_person("elad" , "horev" , 226);
    pperson p6 = creat_person("liad" , "gutlib" , 227);

    SetAdptArrayAt(personArr,0,p1);
    printf("%d\n" , GetAdptArraySize(personArr)); //should print 1

    SetAdptArrayAt(personArr,1,p2);
    printf("%d\n" , GetAdptArraySize(personArr)); // should print 2

    SetAdptArrayAt(personArr,2 , p3);
    printf("%d\n" , GetAdptArraySize(personArr)); //should print 3

    SetAdptArrayAt(personArr, 27 , p4);
    printf("%d\n" , GetAdptArraySize(personArr)); //should print 28

    PrintDB(personArr); // should print 4 persons


    SetAdptArrayAt(personArr, 15 , p5);

    SetAdptArrayAt(personArr, 9 , p6);

    pperson  p = GetAdptArrayAt(personArr , 7); // should return NULL
    if(p == NULL)
        printf("NULL");
    else
        print_person(p);

    pperson r = GetAdptArrayAt(personArr , 9);

    printf("%s\n" , r->first_name); // should print liad
    printf("%s\n" , r->last_name); // should print gutlib
    printf("%d\n" , r->id); // should print 227

    PrintDB(personArr); // should print 6 persons

    DeleteAdptArray(personArr);
    delete_person(p1);
    delete_person(p2);
    delete_person(p3);
    delete_person(p4);
    delete_person(p5);
    delete_person(p6);
    delete_person(r);






    return 0;
}