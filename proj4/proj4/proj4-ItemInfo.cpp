/**
 * file:  proj4-ItemInfo.cpp
 * author: Jan Jasa
 * course: CSI 1440
 * assignment:  project 4
 * due date: 2/27/2023
 *
 */

 //NOTE: ALL FUNCTIONS MUST KEEP IN MIND OF
 // NEGATIVE VALUES, 48 ASCII CODE FOR START

 #include "proj4-ItemInfo.hpp"

 void ItemInfo::setItemId(const char *num){
     this->itemId = stuCstrToDbl(num);
 }

 void ItemInfo::setDescription(const char *cstr){
     //point temp to description
     char *temp = this->description;
     while(*cstr != '\0'){
        *temp = *cstr;
        temp++;
        cstr++;
     }
     *temp = '\0';
 }

 void ItemInfo::setManCost(const char *num){
     this->manCost = stuCstrToDbl(num);
 }

 void ItemInfo::setSellPrice(const char *num){
     this->sellPrice = stuCstrToDbl(num);
 }

 int ItemInfo::getItemId(){
     return this->itemId;
 }
 const char *ItemInfo::getDescription(){
     return this->description;
 }

 double ItemInfo::getManCost(){
     return this->manCost;
 }

 double ItemInfo::getSellPrice(){
     return this->sellPrice;
 }

 void ItemInfo::toAmazonJSON(ostream &out){
     //format: itemId,decription,manufacturingCost,sellingPrice
     char id[15] = "{\n\t\t\"itemId\": ";
     char desc[19] = "\n\t\t\"description\": ";
     char man[16] = "\n\t\t\"manPrice\": ";
     char sell[18] = "\n\t\t\"sellPrice\": ";
     printCString(out, id);
     stuDblToCstr(id, this->itemId);
     printCString(out, id);

     printCString(out, desc);
     printCString(out, this->description);

     printCString(out, man);
     stuDblToCstr(man, this->manCost);
     printCString(out, man);

     printCString(out, sell);
     stuDblToCstr(sell, this->sellPrice);
     printCString(out, sell);

     out.put('\n');
     out.put('\t');
     out.put('}');
     out.put(',');
     out.put('\n');
 }

 void ItemInfo::displayItemInfo(ostream &out){
    char id[9] = "itemId: ";
    char desc[15] = "\ndescription: ";
    char man[11] = "\nmanCost: ";
    char sell[13] = "\nsellPrice: ";
    char calc[20] = "\ncalculatedProfit: ";

    printCString(out, id);
    stuDblToCstr(id, this->itemId);
    printCString(out, id);

    printCString(out, desc);
    printCString(out, this->description);

    printCString(out, man);
    stuDblToCstr(man, this->manCost);
    printCString(out, man);

    printCString(out, sell);
    stuDblToCstr(sell, this->sellPrice);
    printCString(out, sell);

    printCString(out, calc);
    stuDblToCstr(calc, calcProfit());
    printCString(out, calc);

    out.put('\n');
 }

 double ItemInfo::calcProfit(){
     return this->sellPrice - this->manCost;
 }


 double stuCstrToDbl (const char *num){
     double returnThis = 0;
     int count = 0;
     bool negative = false;

     //check if input is negative
     if(*num == '-'){
        negative = true;
        num++;
     }
     //potential end variables: \0 and .
     while(*num != '\0' && *num != '.'){
        if(count != 0){
            //for each digit
            returnThis *= 10;
        }
        returnThis += *num - '0';
        count++;
        num++;
     }
     //decimals incase \0 wasnt endpoint
     int decimalspot=0;
     while(*num != '\0'){
        //tenths place
        if(decimalspot==0){
           num++;
            returnThis += 0.1 * (*num - '0');
        }
        //hundredths
        else{
            returnThis += 0.01 * (*num - '0');
        }
        num++;
        decimalspot++;
     }
     //output
     if(!negative){
        return returnThis;
     }
     else{
        return returnThis * -1;
     }
 }

 void stuDblToCstr(char *cstr, double num){
     int x=0;
     int count=0;
     int beforeDecimal = num;
     bool negative = false;
     char temp;
     double decimals;

     //check negatives
     if(num < 0){
        cstr[x] = '-';
        x++;
        negative = true;
        num*=-1;
        beforeDecimal = num;
     }

     while(beforeDecimal>0){
        cstr[x] = char(beforeDecimal%10 + '0');
        beforeDecimal /= 10;
        x++;
        count++;
     }
     //reverse char array method
     if(negative){
        for(int i=0; i<count/2; i++){
            temp = cstr[i+1];
            cstr[i+1] = cstr[count-i-1];
            cstr[count-i-1] = temp;
         }
     }
     else{
        for(int i=0; i<count/2; i++){
            temp = cstr[i];
            cstr[i] = cstr[count-i-1];
            cstr[count-i-1] = temp;
         }
     }

     //decimals!
    decimals = num-(int(num));
     if(decimals>0){
        cstr[x] = '.';
        x++;
        for(int i=0; i<2; i++){
            decimals*=10;
            cstr[x] = char(int(decimals) + '0');
            decimals = decimals-(int(decimals));
            x++;
        }
     }
     cstr[x] = '\0';
 }

 void stuCstrCpy(char *dest, const char *src){
    int count = 0;
    while(src[count] != '\0'){
        dest[count] = src[count];
        count++;
    }
    dest[count] = '\0';
 }

 int stuCstrLen(const char *src){
    int count = 0;
    while(*src != '\0'){
        count++;
        src++;
    }
    return count;
}

ostream& printCString(ostream &out, const char *src){
    int count = 0;
    while(src[count] != '\0'){
        out.put(src[count]);
        count++;
    }
    return out;

}
