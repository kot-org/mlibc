
#include <langinfo.h>
#include <bits/ensure.h>
#include <mlibc/debug.hpp>

char *nl_langinfo(nl_item item) {
	if(item == CODESET) {
		return const_cast<char *>("UTF-8");
	} else if(item >= ABMON_1 && item <= ABMON_12) {
		switch(item) {
			case ABMON_1: return const_cast<char *>("Jan");
			case ABMON_2: return const_cast<char *>("Feb");
			case ABMON_3: return const_cast<char *>("Mar");
			case ABMON_4: return const_cast<char *>("Apr");
			case ABMON_5: return const_cast<char *>("May");
			case ABMON_6: return const_cast<char *>("Jun");
			case ABMON_7: return const_cast<char *>("Jul");
			case ABMON_8: return const_cast<char *>("Aug");
			case ABMON_9: return const_cast<char *>("Sep");
			case ABMON_10: return const_cast<char *>("Oct");
			case ABMON_11: return const_cast<char *>("Nov");
			case ABMON_12: return const_cast<char *>("Dec");
		}
		__builtin_unreachable();
	} else if(item >= MON_1 && item <= MON_12) {
		switch(item) {
			case MON_1: return const_cast<char *>("January");
			case MON_2: return const_cast<char *>("Feburary");
			case MON_3: return const_cast<char *>("March");
			case MON_4: return const_cast<char *>("April");
			case MON_5: return const_cast<char *>("May");
			case MON_6: return const_cast<char *>("June");
			case MON_7: return const_cast<char *>("July");
			case MON_8: return const_cast<char *>("August");
			case MON_9: return const_cast<char *>("September");
			case MON_10: return const_cast<char *>("October");
			case MON_11: return const_cast<char *>("November");
			case MON_12: return const_cast<char *>("December");
		}
		__builtin_unreachable();
	} else if(item == AM_STR) {
		return const_cast<char *>("AM");
	} else if(item == PM_STR) {
		return const_cast<char *>("PM");
	}else{
		mlibc::infoLogger() << "mlibc: nl_langinfo item "
				<< item << " is not implemented properly" << frg::endlog;
		return const_cast<char *>("");
	}
}

char *nl_langinfo_1(nl_item, locale_t) {
	__ensure(!"Not implemented");
	__builtin_unreachable();
}

