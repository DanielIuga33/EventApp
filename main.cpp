#include "Teste.h"
#include "UI.h"
int main() {
	Service srv;
	Validator validator;
	UI ui(srv, validator);
	ui.run();
 }