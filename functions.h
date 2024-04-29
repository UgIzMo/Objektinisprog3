#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>

/**
 * @brief Enumeracinė klasė, apibrėžianti skirtingus konteinerių tipus.
 */
enum class ContainerType { None, Vector };

/**
 * @brief Enumeracinė klasė, apibrėžianti skirtingas atliekamas veiksmų rūšis.
 */
enum class Action { None, Generate, Sort };

/**
 * @brief Funkcija, kuri klauso vartotojo pasirinkimo dėl atliekamų veiksmų.
 * @return Pasirinktas veiksmas.
 */
Action getActionChoice();

/**
 * @brief Atlieka nurodytą veiksmą su pasirinktu konteineriu ir nurodytomis dydžio reikšmėmis.
 * @param containerChoice Konteinerio tipas, su kuriuo bus atliekamas veiksmas.
 * @param actionChoice Veiksmas, kurį reikia atlikti.
 * @param sizes Konteinerių dydžių sąrašas.
 */
void performAction(ContainerType containerChoice, Action actionChoice, const std::vector<int>& sizes);

/**
 * @brief Paleidžia programą.
 * 
 * Ši funkcija yra pagrindinės programos logikos dalis.
 * Ji klauso vartotojo pasirinkimo dėl konteinerio ir veiksmo ir atlieka pasirinktą veiksmą.
 */
void runApp();

#endif // FUNCTIONS_H
