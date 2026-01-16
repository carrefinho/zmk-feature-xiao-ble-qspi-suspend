# XIAO BLE QSPI Flash Suspend

A ZMK Zephyr module that puts the XIAO BLE's external QSPI flash (P25Q16H) into deep power-down mode at boot to save about 10µA idle power consumption. The flash is unused by ZMK since settings are stored on internal flash.

See also: [Nordic's power optimization recommendations](https://docs.nordicsemi.com/bundle/ncs-3.1.0/page/nrf/test_and_optimize/optimizing/power_general.html#put_the_external_flash_into_sleep_mode_in_inactivity_periods) on suspending external flash.

## Usage

Add this module to your `config/west.yml`:

```yaml
manifest:
  remotes:
    - name: zmkfirmware
      url-base: https://github.com/zmkfirmware
    - name: carrefinho
      url-base: https://github.com/carrefinho
  projects:
    - name: zmk
      remote: zmkfirmware
      revision: main
      import: app/west.yml
    - name: zmk-feature-xiao-ble-qspi-suspend
      remote: carrefinho
      revision: main
  self:
    path: config
```

The module is enabled by default when building for `xiao_ble`. To disable, add to your `.conf` file:

```
CONFIG_XIAO_BLE_SUSPEND_QSPI_FLASH=n
```
