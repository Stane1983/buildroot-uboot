m3_mid_reff08_config: unconfig
	$(MKCONFIG) $(@:_config=)  arm aml_meson m3_mid_reff08  amlogic m3
m3_mid_reff08_config_help:
	@echo =======================================================================
	@echo The mark in board is "AML8726-M3_MID_reff08"
	@echo config command: \"make $(@:%_help=%)\"
help:m3_mid_reff08_config_help
