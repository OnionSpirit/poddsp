#pragma once


namespace PodDSP{

    /// Амплитудный модулятор,
    /// Наносит информацию на несущую, задавая огибающую выходного сигнала по форме информационного сигнала,
    /// и сохраняет частоту его радиоимпульсного заполнения, как у несущего сигнала.
    /// Параметры:
    /// 1) Несущий сигнал.
    /// 2) Информационный сигнал.
    /// 3) Глубина модуляции, по умолчанию 0.3 (30%)
    /// Информационный сигнал накладывается на весь несущий сигнал вне зависимости от размеров буферов с отсчётами.
    /// Максимально допустимая глубина модуляции 100%
    std::vector<std::complex<float>> complexMagModulator(const std::vector<std::complex<float>> &,
                                                         const std::vector<float> &,
                                                         const float & = 0.3f);
/// Амплитудный демодулятор.
/// Снимает информационный сигнал с амплитудно модулированного колебания,
/// непригоден для использования с сигналами, с глубиной модуляции выше 100%.
    std::vector<float> complexMagDemodulator(const std::vector<std::complex<float>> &) noexcept;

    ///BPSK модулятор. Модулирует фазу несущей согласно информационной последовательности 0 и 1.
    /// Параметры:
    /// 1) Несущий сигнал.
    /// 2) Информационная последовательность.
    /// Длина информационной последовательности должна совпадать с колличеством периодов в передаваемом кадре несущей.
    /// Кадр несущей перед модуляцией следует выбирать с нулевой начальной фазой.
    /// Первый символ информациооной последовательности всегда пропадает.
    std::vector<std::complex<float>> complexBPSKModulator(const std::vector<std::complex<float>> &,
                                                          const std::vector<bool> &);
}