//------------------------------------------------------------------------------
// MIT License
//------------------------------------------------------------------------------
// 
// Copyright (c) 2020 Thakee Nathees
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//------------------------------------------------------------------------------


#include "core/carbon.h"
using namespace carbon;

// TODO: define RUN_TESTS from build system.
#if DEBUG_BUILD
#define RUN_TESTS
#endif

#ifdef RUN_TESTS
#include "tests/carbon_tests.h"
#endif
// TODO: VarError -> Error.
// TODO: Make var submodule to local.

int _main(int argc, char** argv) {

	initialize();

	//ptr<Parser> parser = newptr<Parser>();
	//Analyzer analyzer;
	//File file = File("tests/analyzer/test_files/z_function.cb", File::READ);
	//String source = file.read_text();
	//try {
	//	parser->parse(source, file.get_path());
	//	analyzer.analyze(parser);
	//} catch (Error& err) {
	//	Logger::logf_error("ERROR(%s): %s ", Error::get_err_name(err.get_type()).c_str(), err.get_msg().c_str());
	//	Logger::logf_info("at: (%s:%i)\n", err.get_file().c_str(), err.get_pos().x);
	//	Logger::log(
	//		String::format("    at: %s (%s:%i)\n", err.get_dbg_func().c_str(), err.get_dbg_file().c_str(), err.get_dbg_line()).c_str(),
	//		Logger::ERROR, Logger::Color::L_SKYBLUE
	//	);
	//	Logger::logf_info("%s\n%s", err.get_line().c_str(), err.get_line_pos().c_str());
	//}

#ifdef RUN_TESTS
	int res = _test_main(argc, argv);
	if (res) {
		Logger::log("\nTests failed. continue? [Y/N] (default:N) ", Logger::VERBOSE, Logger::Color::L_WHITE);
		char _continue = getchar();
		if (_continue != 'Y' && _continue != 'y') {
			return res;
		}
		CLEAR_GETCHAR_BUFFER();
	}
#endif // DEBUG_BUILD

	Logger::log("\nPress enter to exit...", Logger::VERBOSE, Logger::Color::L_SKYBLUE);
	getchar(); // pause
	return 0;
}
