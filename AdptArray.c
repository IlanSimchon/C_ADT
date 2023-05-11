#include "AdptArray.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"


typedef struct AdptArray_ {
    PElement* arr;
    int size;
    COPY_FUNC copy;
    DEL_FUNC del;
    PRINT_FUNC print;

}AdptArray_, *PAdptArray;



PAdptArray CreateAdptArray(COPY_FUNC copy, DEL_FUNC del,PRINT_FUNC print){
    PAdptArray myAdpt = (PAdptArray)malloc(sizeof(AdptArray_));
    if(myAdpt == NULL)
        printf("Error");

    myAdpt->arr = NULL;
    myAdpt->size = 0;
    myAdpt->copy = copy;
    myAdpt->del = del;
    myAdpt->print = print;

    return myAdpt;
}

void DeleteAdptArray(PAdptArray myAdpt){
    for (int i = 0 ; i < myAdpt->size ; i++){
        if(myAdpt->arr[i] != NULL)
            myAdpt->del(myAdpt->arr[i]);
    }
    free(myAdpt->arr);
    free(myAdpt);
}

Result SetAdptArrayAt(PAdptArray myAdpt, int index, PElement element){
    if(myAdpt) {
        if (myAdpt->size <= index) {
            PElement newPelem = (PElement)calloc((index + 1), sizeof(element));
            if(newPelem == NULL) {
                printf("error");
                return FAIL;
            }
            memcpy(newPelem, myAdpt->arr, myAdpt->size * sizeof(element));
            free(myAdpt->arr);
            myAdpt->arr = newPelem;
            myAdpt->size = index + 1;
        } else if ((myAdpt->arr)[index] != NULL) { // if the first if is true the second if cant be true
            myAdpt->del((myAdpt->arr)[index]);
        }
        (myAdpt->arr)[index] = myAdpt->copy(element);

        return SUCCESS;
    }
    return FAIL;
    }

PElement GetAdptArrayAt(PAdptArray myAdpt, int index){
    if(! (myAdpt->arr)[index])
        return NULL;
    PElement get = myAdpt->copy((myAdpt->arr)[index]);
    return get;
}

int GetAdptArraySize(PAdptArray myAdpt){
    if(! myAdpt)
        return -1;
    return myAdpt->size;
}

void PrintDB(PAdptArray myAdpt){
    for (int i = 0; i < myAdpt->size; ++i) {
        if(myAdpt->arr[i] != NULL)
            myAdpt->print(myAdpt->arr[i]);
    }
}
