SRCDIR                          = $(dir $(lastword $(MAKEFILE_LIST)))
BUILDDIR                        = $(shell pwd)
PHP_TEST_SETTINGS               = -d 'open_basedir=' -d 'output_buffering=0' -d 'memory_limit=-1'
PHP_DEPRECATED_DIRECTIVES_REGEX = '^(magic_quotes_(gpc|runtime|sybase)?|(zend_)?extension(_debug)?(_ts)?)[\t\ ]*='
PHP_EXECUTABLE                 ?= $(shell which php)
EGREP                           = /bin/grep -E
PHP_CPPFLAGS                    = $(shell php-config --includes) -I$(SRCDIR)../include -I$(SRCDIR)../ -std=c++11
PHP_LDFLAGS                     = -shared -Wl,-rpath,'$$ORIGIN/../' -L$(SRCDIR)../ -lphpcpp $(shell php-config --ldflags) 

CXX_SRC  = main.cpp functions.cpp donothingnative.cpp
OBJS     = $(patsubst %.cpp,%.o,$(CXX_SRC))
SRC_DEPS = $(patsubst %.cpp,%.d,$(CXX_SRC))

TARGET   = phpcpptest.so

all: $(TARGET)

phpcpptest.so: $(OBJS)
	$(CXX) $^ $(PHP_LDFLAGS) $(LDFLAGS) -o "$@"

%.o: %.cpp
	$(CXX) $(PHP_CPPFLAGS) -fpic $(CXXFLAGS) -c "$<" -o "$@"

clean: clean-deps clean-coverage
	-rm -f $(TARGET) $(OBJS)

clean-deps:
	-rm -f $(SRC_DEPS)

ifeq (,$(findstring clean,$(MAKECMDGOALS)))
-include $(SRC_DEPS)
endif

%.d : %.cpp
	$(CXX) -MM -MP -MF"$@" -MT"$(@:%.d=%.o)" -MT"$@" $(PHP_CPPFLAGS) "$<"

test: all
	@if test ! -z "$(PHP_EXECUTABLE)" && test -x "$(PHP_EXECUTABLE)"; then \
		INI_FILE=`$(PHP_EXECUTABLE) -d 'display_errors=stderr' -r 'echo php_ini_loaded_file();' 2> /dev/null`; \
		if test "$$INI_FILE"; then \
			$(EGREP) -h -v $(PHP_DEPRECATED_DIRECTIVES_REGEX) "$$INI_FILE" > $(BUILDDIR)/tmp-php.ini; \
		else \
			echo > $(BUILDDIR)/tmp-php.ini; \
		fi; \
		INI_SCANNED_PATH=`$(PHP_EXECUTABLE) -d 'display_errors=stderr' -r '$$a = explode(",\n", trim(php_ini_scanned_files())); echo $$a[0];' 2> /dev/null`; \
		if test "$$INI_SCANNED_PATH"; then \
			INI_SCANNED_PATH=`dirname $$INI_SCANNED_PATH`; \
			$(EGREP) -h -v $(PHP_DEPRECATED_DIRECTIVES_REGEX) "$$INI_SCANNED_PATH"/*.ini >> $(BUILDDIR)/tmp-php.ini; \
		fi; \
		TEST_PHP_EXECUTABLE=$(PHP_EXECUTABLE) \
		TEST_PHP_SRCDIR=$(SRCDIR) \
		NO_INTERACTION=1 $(PHP_EXECUTABLE) -n -c $(BUILDDIR)/tmp-php.ini $(PHP_TEST_SETTINGS) $(SRCDIR)/run-tests.php -n -c $(BUILDDIR)/tmp-php.ini -d extension_dir=$(BUILDDIR) -d 'extension=$(TARGET)' $(TESTS); \
		TEST_RESULT_EXIT_CODE=$$?; \
		rm $(BUILDDIR)/tmp-php.ini; \
		exit $$TEST_RESULT_EXIT_CODE; \
	else \
		echo "ERROR: Cannot run tests without CLI sapi."; \
	fi

clean-coverage:
	-rm -rf .coverage coverage

coverage: clean-coverage
	$(MAKE) CXXFLAGS="-O0 -coverage" LDFLAGS="-coverage" test
	lcov -q -d $(BUILDDIR) -d $(SRCDIR)../shared/common -d $(SRCDIR)../shared/zend --capture --base-directory=$(SRCDIR)../ -o $(BUILDDIR)/.coverage
	lcov -q -r $(BUILDDIR)/.coverage "/usr/include/*" "$(shell php-config --include-dir)/*" -o $(BUILDDIR)/.coverage
	genhtml --quiet --legend --output-directory $(BUILDDIR)/coverage/ --title "PHP-CPP Code Coverage" $(BUILDDIR)/.coverage