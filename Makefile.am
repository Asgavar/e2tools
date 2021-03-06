########################################################################
# autotools control definitions
########################################################################

ACLOCAL_AMFLAGS = -I m4 -I e2t-m4


########################################################################
# e2tools variables to append to
########################################################################

# hook targets
all_targets =
clean_targets =
install_targets =
uninstall_targets =
phony_targets =

# list of e2tools like e2ls and e2cp etc
e2tools_list =

# list of -e 's|||g' arguments to sed for preprocessing *.in files
sed_in_commands =


########################################################################
# Automake variables to append to
########################################################################

BUILT_SOURCES =
CLEANFILES =
EXTRA_DIST =
SUFFIXES =
TESTS =

bin_PROGRAMS =
dist_man_MANS =
man_MANS =


########################################################################
# Documentation files
########################################################################

EXTRA_DIST += DEVELOPMENT.md
EXTRA_DIST += NEWS.md
EXTRA_DIST += README.md
EXTRA_DIST += TODO


########################################################################
# Define e2tools
########################################################################

bin_PROGRAMS += e2tools

e2tools_CFLAGS =
e2tools_CPPFLAGS =
e2tools_LDADD =

# e2tools_CFLAGS   += -save-temps=obj

e2tools_CPPFLAGS += $(EXT2FS_CFLAGS)
e2tools_LDADD    += $(EXT2FS_LIBS)

e2tools_CPPFLAGS += $(COM_ERR_CFLAGS)
e2tools_LDADD    += $(COM_ERR_LIBS)

e2tools_SOURCES =
e2tools_SOURCES += compiler-definitions.h
e2tools_SOURCES += e2tools.c e2tools.h
e2tools_SOURCES += elist.c elist.h
e2tools_SOURCES += progress.c progress.h
e2tools_SOURCES += read.c read.h
e2tools_SOURCES += util.c util.h
e2tools_SOURCES += write.c write.h

dist_man_MANS += e2tools.7

if HAVE_EXT2FS_XATTRS
# EXTRA_DIST       += e2chcon.1in
# CLEANFILES       += e2chcon.1
# man_MANS         += e2chcon.1
# e2tools_list     += e2chcon
endif

e2tools_SOURCES  += e2tool-e2cp.c
e2tools_SOURCES  += e2tool-e2cp.h
dist_man_MANS    += e2cp.1
e2tools_list     += e2cp

e2tools_SOURCES  += e2tool-e2ln.c
e2tools_SOURCES  += e2tool-e2ln.h
dist_man_MANS    += e2ln.1
e2tools_list     += e2ln

e2tools_SOURCES  += e2tool-e2ls.c
e2tools_SOURCES  += e2tool-e2ls.h
EXTRA_DIST       += e2ls.1.in
CLEANFILES       += e2ls.1
man_MANS         += e2ls.1
e2tools_list     += e2ls
e2ls.1 : e2ls.1.in Makefile

e2tools_SOURCES  += e2tool-e2mkdir.c
e2tools_SOURCES  += e2tool-e2mkdir.h
dist_man_MANS    += e2mkdir.1
e2tools_list     += e2mkdir

e2tools_SOURCES  += e2tool-e2mv.c
e2tools_SOURCES  += e2tool-e2mv.h
dist_man_MANS    += e2mv.1
e2tools_list     += e2mv

e2tools_SOURCES  += e2tool-e2rm.c
e2tools_SOURCES  += e2tool-e2rm.h
dist_man_MANS    += e2rm.1
e2tools_list     += e2rm

e2tools_SOURCES  += e2tool-e2tail.c
e2tools_SOURCES  += e2tool-e2tail.h
dist_man_MANS    += e2tail.1
e2tools_list     += e2tail

# Put this rule after all appends to the e2tools_list variable
e2tools_SOURCES += e2tools-toolmap.h
BUILT_SOURCES   += e2tools-toolmap.c
CLEANFILES      += e2tools-toolmap.c
e2tools_SOURCES += e2tools-toolmap.c
e2tools-toolmap.c: Makefile
	@( \
	echo "/* autogenerated from Makefile.am */"; \
	echo "#include <stddef.h>"; \
	echo "#include \"e2tools-toolmap.h\""; \
	for tool in $(e2tools_list); do \
		echo "#include \"e2tool-$${tool}.h\""; \
	done; \
	echo "struct toolmap_element toolmap[] = {"; \
	for tool in $(e2tools_list); do \
		echo "  {\"$${tool}\", main_$${tool}},"; \
	done; \
	echo "  {NULL, NULL}"; \
	echo "};"; \
	) > e2tools-toolmap.c.tmp
	@if test -f e2tools-toolmap.c && cmp e2tools-toolmap.c e2tools-toolmap.c.tmp >/dev/null 2>&1; then \
		echo "Keeping unchanged e2tools-toolmap.c"; \
		rm -f e2tools-toolmap.c.tmp; \
	else \
		echo "Updating e2tools-toolmap.c"; \
		mv -f e2tools-toolmap.c.tmp e2tools-toolmap.c; \
	fi

all_targets   += e2tools-symlinks
phony_targets += e2tools-symlinks
e2tools-symlinks: e2tools$(EXEEXT)
	@for symlink in $(e2tools_list); do \
		rm -f "$${symlink}"; \
		$(LN_S) e2tools "$${symlink}" || exit 1; \
	done

clean_targets += e2tools-clean
phony_targets += e2tools-clean
e2tools-clean:
	-rm -f $(e2tools_list)

install_targets += e2tools-install
phony_targets   += e2tools-install
e2tools-install:
	cd $(DESTDIR)$(bindir) && \
	for symlink in $(e2tools_list); do \
		rm -f "$${symlink}"; \
		$(LN_S) e2tools "$${symlink}" || exit 1; \
	done

uninstall_targets += e2tools-uninstall
phony_targets     += e2tools-uninstall
e2tools-uninstall:
	-cd $(DESTDIR)$(bindir) && rm -f $(e2tools_list)


########################################################################
# include files
########################################################################

include tests/Makefile-files


########################################################################
# .in replacement rules
########################################################################

HASHMARK = \#

if HAVE_EXT2FS_XATTRS
sed_in_commands += -e 's|[@]HAVE_EXT2FS_XATTRS_MAN_FALSE@||g'
sed_in_commands += -e 's|[@]HAVE_EXT2FS_XATTRS_MAN_TRUE@|.\\" |g'
sed_in_commands += -e 's|[@]HAVE_EXT2FS_XATTRS_FALSE@||g'
sed_in_commands += -e 's|[@]HAVE_EXT2FS_XATTRS_TRUE@|$(HASHMARK) |g'
else
sed_in_commands += -e 's|[@]HAVE_EXT2FS_XATTRS_MAN_FALSE@|.\\" |g'
sed_in_commands += -e 's|[@]HAVE_EXT2FS_XATTRS_MAN_TRUE@||g'
sed_in_commands += -e 's|[@]HAVE_EXT2FS_XATTRS_FALSE@|$(HASHMARK) |g'
sed_in_commands += -e 's|[@]HAVE_EXT2FS_XATTRS_TRUE@||g'
endif

sed_in_commands += -e 's|[@]top_builddir@|$(top_builddir)|g'
sed_in_commands += -e 's|[@]top_srcdir@|$(top_srcdir)|g'
sed_in_commands += -e 's|[@]DD@|$(DD)|g'
sed_in_commands += -e 's|[@]MKE2FS@|$(MKE2FS)|g'

SUFFIXES += .1.in .1
.1.in.1:
	$(MKDIR_P) $(@D)
	$(SED) $(sed_in_commands) < $< > $@

SUFFIXES += .sh.in .sh
.sh.in.sh:
	$(MKDIR_P) $(@D)
	$(SED) $(sed_in_commands) < $< > $@
	$(CHMOD) +x $@


########################################################################
# local hooks we have collected targets in variables for
########################################################################

.PHONY: $(phony_targets)

all-local: $(all_targets)

install-exec-hook: $(install_targets)

uninstall-hook: $(uninstall_targets)

clean-local: $(clean_targets)
	-rm -f *.i *.s


########################################################################
# End of Makefile.am
########################################################################
