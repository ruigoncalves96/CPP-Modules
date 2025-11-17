./exec > text.log
diff -u <(sed -E 's/^\[[^]]+\]\s*//' 19920104_091532.log) <(sed -E 's/^\[[^]]+\]\s*//' text.log)
