// Importieren der verwendeten Bibliotheken
#include <stdio.h>
#include <stdbool.h>


// Reihenfolge der Buchstabenhäufigkeiten der verschiedenen Sprachen
const char languages[][26] = {"ENISRATDHULCGMOBWFKZPVJYXQ", "ETAOINSHRDLCUMWFGYPBVKJXQZ", "EAOSRNIDLCTUMPBGYVQHFZJXWK", "EAIONLRTSCDPUMVGHFBQZYJXWK"};

// verschiedene Sprachen
const char languagesNames[][12] = {"Deutsch", "Englisch", "Spanisch", "Italienisch"};

/**
 * Funktion, die die Anzahl an Zeichen der Datei berechnet.
 * 
 * @return int : Anzahl an Zeichen
 */
int sizeOfFile(){
    int i;
    for(i = 0; getchar() != EOF; i++); // Schleife zum Zählen
    rewind(stdin); // Eingabe zurücksetzen
    return i;
}

/**
 * Diese Funktion ließt, die Datei ein und speichert die Zeichen in einem Array.
 * 
 * @param size : Anzahl an Zeichen
 * @param input : Zeiger auf Array
 * @return char* : Zeiger auf Array
 */
char * readFile(int size, char * input){
    int c;
    for(int i = 0; (c = getchar()) != EOF; i++) input[i] = c;
    return input;
}

/**
 * Zählt die Anzahl für jedes Zeichen im ASCII-256 Standard
 * 
 * @param input : Array mit allen Zeichen
 * @param count : Zeiger auf 256 langes "Zähl"-Array (Anzahl von jedem Zeichen)
 * @param size : Anzahl an Zeichen
 * @return int* : Zeiger auf "Zähl"-Array
 */
int * charCount(char * input, int * count, int size){
    for(int i = 0; i < 256; i++) count[i] = 0; // Alle Werte auf den Wert 0 initialisieren
    for(int i = 0; i < size; i++) count[input[i]]++;
    return count;
}

/**
 * Berechnet den Anteil für jeden Buchstaben von A-Z bzw. a-z bezogen auf die Gesamtanzahl an Zeichen.
 * Dabei werden z.B. die Wahrscheinlichkeiten von a und A addiert.
 * 
 * @param count : Zeiger auf "Zähl"-Array
 * @param prozentCount : 26 langes Array für die Wahrscheinlichkeiten von A-Z
 * @param size : Anzahl an Zeichen
 * @return double* : Zeiger auf Wahrscheinlichkeits-Array
 */
double * prozent(int * count, double * prozentCount, int size){
    for(int i = 'A'; i <= 'Z'; i++) prozentCount[i-'A'] = (double)count[i] / (double)size; // Wahrscheinlichkeit für 'A' bis 'Z'
    for(int i = 'a'; i <= 'z'; i++) prozentCount[i-'a'] += (double)count[i] / (double)size; // Addieren der Wahrscheinlichkeiten von 'a' bis 'z'
    return prozentCount;
}

/**
 * Sortiert das Wahrscheinlichkeits-Array mit Hilfe von Bubble-Sort.
 * Außerdem wird ein zweites Array von 0-25 anhand des Wahrscheinlichkeits-Arrays sortiert, 
 * dies bring die Reihenfolge der Buchstaben nach ihrer Häufigkeit.
 * 
 * @param list : Zeiger auf Wahrscheinlichkeits-Array
 * @param arr : Zeiger auf Array mit Werten von 'A' bis 'Z' (Länge 26)
 * @return char* : Zeiger auf Array mit Reihenfolge der Buchstaben nach Häufigkeit (z.B. "EANOI...")
 */
char * sort(double * list, char * arr){
    double tmpDouble; // Cache-Variable (double) definieren
    char tmpChar; // Cache-Variable (char) definieren
    for(int i = 0; i < 26; i++) arr[i] = 'A'+i;
    for (int i = 25; i >= 0; i--){
        for (int j = 25; j > 25 - i; j--){
            if (list[j] > list[j - 1]){
                // Dreieckstausch  Wahrscheinlichkeits-Array
                tmpDouble = list[j];
                list[j] = list[j - 1];
                list[j - 1] = tmpDouble;

                // Dreieckstausch Buchstaben-Array
                tmpChar = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmpChar;
            }
        }
    }
    return arr;
}

/**
 * Diese Funktion erkennt die Sprache der Funktion. Dabei wird für jeden Sprache die Prozentuale Übereinstimmung
 * ausgegeben und die Wahrscheinlichkeit der Wahrscheinlichsten Sprache ausgegeben.
 * 
 * @param prozentCount : Zeiger auf Wahrscheinlichkeits-Array
 */
void spracheErkennen(double * prozentCount){
    char sortedArr[26];
    char * sortedCount = sort(prozentCount, sortedArr); // sortieren des Arrays
    double languageValues[4];
    for(int i = 0; i < 4; i++){ // Übereinstimmung für jede Sprache bestimmen
        languageValues[i] = vergleiche(sortedCount, languages[i]);
        printf("Zu %f %% mit der %sen Buchstabenhaeufigkeit uebereinstimmend\n", languageValues[i], languagesNames[i]);
    }
    double max = 0.0;
    int maxIndex = 0;
    double sum = 0.0;
    for(int i = 0; i < 4; i++){ // Maximum und Index des Maximums bestimmen
        sum+=languageValues[i];
        if(languageValues[i] > max) max = languageValues[i], maxIndex = i;
    }
    for(int i = 0; i < 75; i++) printf("_");
    // Finales-Ergebnis ausgeben
    printf("\nInsgesamt ist %s mit %f %% am Wahrscheinlichsten", languagesNames[maxIndex], (max/(sum/100.0)));
}

/**
 * Vergleicht die eingelese Buchstabenhäufigkeits-Liste mit einer vorgefertigten Sprachen Buchstabenhäufigkeits-Liste
 * 
 * @param readList : Eingelesene Liste
 * @param languageList : Sprachen Liste
 * @return double : Übereinstimmung in Prozent
 */
double vergleiche(char * readList, const char * languageList){
    int j = 0;
    double prozent = 0;
    for(int i = 0; i < 26; i++){
        if(readList[i] == languageList[j]) prozent += 1.0/26.0; // 1/26tel addieren 
        while(check(languageList[j], readList, i)) j++; // Schon vorgekommene Buchstaben überspringen
    }
    return prozent*100; // Prozent Zahl aus geben
}

/**
 * Überpürft, ob Buchstabe in der eingelesenen Buchstabenreihenfolge schon vorkam
 * 
 * @param c : Aktueller Buchstabe in Buchstabenreihenfolge einer Sprache
 * @param readList : Eingelesene Buchstabenreihenfolge
 * @param i : Aktuelle Stelle
 * @return true : Buchstabe ist vorhanden
 * @return false : Buchstabe ist nicht vorhanden
 */
bool check(char c, char * readList, int i){
    for(int j = 0; j <= i; j++) if(readList[j] == c) return true;
    return false;
}

/**
 * Main-Funktion: Startet das Programm, ruft in der entsprechenden Reihenfolge die Funktion auf und erstellt Arrays
 * Die Arrays müssen in der Main-Funktion erstellt werden, da man zum keine Arrays als Rückgabewert verwenden kann und
 * beim Erstellen der Arryas in Funktion diese nach Ende der Funktion wieder gelöscht werden. Um trotzdem die in "main"
 * erstellten Arrays zu verändern, werden die Arrays an die Funktionen übergeben und danach nur noch über den zugewiesenen
 * Zeiger (*) angesprochen. Daher sind die Name der Arrays (a,b,c) irrelevant.
 * 
 * @return int : Rückgabewert des Programms (immer 0)
 */
int main(){
    int size = sizeOfFile(); // Länge lesen
    char a[size];
    char * input = readFile(size, a); // Buchstaben lesen
    int b[257];
    int * count = charCount(input, b, size); // Buchstaben zählen
    double c[26];
    double * prozentCount = prozent(count, c, size); // Wahrscheinlichkeiten berechnen
    spracheErkennen(prozentCount); // Sprache erkennen
    return 0;
}