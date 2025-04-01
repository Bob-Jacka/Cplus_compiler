/*
Compiler entry point.
*/

#include <variables.hpp>

int main(int argc, char* argv[]) {
    if (argc == 2) {
        //
    }
};

/*
Функция для проверки флагов командной строки.
*/
void check_flags(string str_to_check) {
	// bool check_func_full = func(string str )  {
	// 	return strings.Contains(str, "=") && (strings.HasPrefix(str, "--") || strings.HasPrefix(str, "-"))
	// }
	if check_func_full(str_to_check) {
		var split_line = strings.Split(str_to_check, "=")
		var flag_name = strings.ToLower(strings.ReplaceAll(split_line[0], "-", ""))
		var flag_value = split_line[1]
		switch flag_name {
		case "suit":
			load_parameters.Suit = flag_value
			break
		case "devices":
			load_parameters.Devices = flag_value
			break
		case "file_save":
			load_parameters.File_save, _ = strconv.ParseBool(flag_value)
			break
		case "file_load":
			load_parameters.File_load, _ = strconv.ParseBool(flag_value)
			break
		case "tc_time":
			load_parameters.Tc_time, _ = strconv.ParseBool(flag_value)
			break
		case "high_prior":
			load_parameters.High_prior, _ = strconv.ParseBool(flag_value)
			break
		case "random_run":
			load_parameters.Random_run, _ = strconv.ParseBool(flag_value)
			break
		case "comments":
			load_parameters.Comments, _ = strconv.ParseBool(flag_value)
			break
		case "colored":
			load_parameters.Colored, _ = strconv.ParseBool(flag_value)
			break
		default:
			colored_txt_output("Unknown flag: "+flag_name, red)
			os.Exit(1)
		}
	} else {
		colored_txt_output("Error occurred in check_flag func.", red)
		os.Exit(1)
	}
}