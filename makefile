#**********************************************************************
# Интерфейсы микроконтроллера.
#**********************************************************************
# Все файлы из папки cfg в каталоге проекта.
MK_INTER_H_FILE			:= $(wildcard module_mc_hardware_interfaces/*.h)
MK_INTER_DIR			:= module_mc_hardware_interfaces
MK_INTER_PATH			:= -I$(MK_INTER_DIR)

# Добавляем к общим переменным проекта.
PROJECT_PATH			+= $(MK_INTER_PATH)