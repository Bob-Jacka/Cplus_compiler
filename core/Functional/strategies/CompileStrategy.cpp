#include <IStrategy.cpp>
#include <Main_types.hpp>

/*
Strategy that compiles program into executable file.
*/
class CompileStrategy : public IStrategy
{
private:
    /* data */
public:
    CompileStrategy(/* args */) {};
    ~CompileStrategy() {};
    void doAlgorithm(void);
};

/*
Algoritm of the compile strategy.
*/
void CompileStrategy::doAlgorithm(void)
{

    program_entites.init_entities();
	controllers.init_controllers();


    controllers->file_controller.open_file(argv[2]);
    

    //End of the algorithm
    program_entites.destroy_entities(); //Перенести в стратегию compile
	controllers.destroy_controllers(); //Перенести в стратегию compile

	delete program_entites; //Перенести в стратегию compile
	delete controllers; //Перенести в стратегию compile
	controllers->file_controller.close_file(); //Перенести в стратегию compile
}
