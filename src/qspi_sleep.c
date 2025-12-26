#include <zephyr/device.h>
#include <zephyr/init.h>
#include <zephyr/logging/log.h>
#include <zephyr/pm/device.h>

LOG_MODULE_REGISTER(xiao_ble_qspi, CONFIG_LOG_DEFAULT_LEVEL);

static int qspi_flash_sleep_init(void) {
    const struct device *flash = DEVICE_DT_GET(DT_NODELABEL(p25q16h));

    if (!device_is_ready(flash)) {
        LOG_ERR("QSPI flash device not ready");
        return -ENODEV;
    }

    int ret = pm_device_action_run(flash, PM_DEVICE_ACTION_SUSPEND);
    if (ret < 0) {
        LOG_ERR("Failed to suspend QSPI flash: %d", ret);
    } else {
        LOG_INF("QSPI flash suspended");
    }

    return ret;
}

SYS_INIT(qspi_flash_sleep_init, POST_KERNEL, 99);
