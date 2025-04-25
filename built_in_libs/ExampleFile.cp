#include 'IO.cp'

using std //use namespace of the std file

public function main() -> undefined
{
	print("Hello World")
}

structure creature {
	string genotype
	int leg_count
}

structure Person by creature {
	string name
	int age
	string gender

	public function print_name() {
		print(this.name)
	}

	public function print_age() {
		print(this.age)
	}

	public function set_name(string another_name) {
		this.name = another_name
	}

	public function set_age(int another_age) {
		this.age = another_age
	}

	public function set_gender(string another_gender) {
		this.gender = another_gender
	}
}

Person human = {.name = "Ivan", .age = 50, .gender = undefined} // or you can write Person human = {.age = 50, .name = "Valerie"}

human.print_name()
human.set_name("Masha")
human.set
human.print_name()

repeat(10) {
	print("Hello world - " + it)
}

/*
1 - from 1, because 0 is not in natural numbers set
2
3
4
5
6
7
8
9
10
*/

//Will be executed 5 times
repeat(5) {
	print("Hello world")

}

do {
	print("Hello world")
} while(1==1) //infinity cycle


int number = 5
do {
	print(number)
	number--

print(number)

} while (number != 1)