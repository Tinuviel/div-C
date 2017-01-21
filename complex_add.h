/* Lovisa Colérus
   2016*/

struct ComplexList{
    List node;
    Complex c;
}
 typedef sruct ComplexLst ComplexList;
 ComplexList *complexListAdd(ComplexList *ls1, ComplexList *ls2);
 ComplexList *complexListRead(FILE *f);
 void complexList;