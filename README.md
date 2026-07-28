<div align="center">

# 🔐 pwmenager

**Кроссплатформенный менеджер паролей на C++Builder и FireMonkey**

[![C++](https://img.shields.io/badge/C++-20-blue.svg?style=for-the-badge&logo=c%2B%2B)](https://isocpp.org/)
[![RAD Studio](https://img.shields.io/badge/RAD%20Studio-12.0-red.svg?style=for-the-badge&logo=embarcadero)](https://www.embarcadero.com/)
[![FireMonkey](https://img.shields.io/badge/FireMonkey-FMX-orange.svg?style=for-the-badge)](https://docwiki.embarcadero.com/RADStudio/Florence/en/FireMonkey)
[![FireDAC](https://img.shields.io/badge/FireDAC-SQLite-green.svg?style=for-the-badge)](https://docwiki.embarcadero.com/RADStudio/en/FireDAC)

![Platform](https://img.shields.io/badge/Windows-0078D6?style=flat-square&logo=windows&logoColor=white)

[О проекте](#-о-проекте) · [Основные возможности](#-основные-возможности) · [Предупреждение](#-важное-предупреждение) · [Технологический стек](#-технологический-стек) · [Установка и запуск](#-установка-и-запуск)

</div>

---

## 📖 О проекте

**pwmenager** — это простое и удобное кроссплатформенное приложение для хранения паролей и учётных записей.
Разработано на **C++** в среде **RAD Studio** с использованием **FireMonkey (FMX)** для интерфейса и **FireDAC** для работы с базой данных **SQLite**.

> 🛡️ **Важно:** Приложение предназначено **только для хранения** данных, но **не обеспечивает криптографическую защиту**. Не рекомендуется использовать его для реальных важных паролей.

---

## ✨ Основные возможности

| Возможность | Описание |
|-------------|----------|
| 🖥️ **Кроссплатформенность** | Работает на Windows (в планах — Android) |
| 🎨 **Современный интерфейс** | Построен на FireMonkey с поддержкой стилей |
| 🗄️ **Локальное хранение** | Все данные сохраняются в SQLite через FireDAC |
| 📋 **Копирование данных** | Один клик для копирования логина/пароля |

---

## ⚠️ Важное предупреждение

> **Данное приложение не использует шифрование!**
> Все пароли и логины хранятся в базе данных SQLite в открытом виде.
> Используйте его только в **изолированных тестовых средах** или для **учебных целей**.

🔒 Для реального использования рекомендуется внедрить шифрование (например, AES-256) перед сохранением данных.

---

## 🛠️ Технологический стек

| Компонент | Технология |
|-----------|------------|
| **Язык** | C++20 (ISO Standard) |
| **IDE** | Embarcadero RAD Studio 12.x |
| **UI Фреймворк** | FireMonkey (FMX) |
| **База данных** | SQLite (через FireDAC) |
| **Целевые ОС** | Windows (Win32/Win64) |

---

## 🚀 Установка и запуск

### Требования
- [RAD Studio 12.x](https://www.embarcadero.com/products/rad-studio) (или новее)
- Компоненты FireDAC (входят в Enterprise/Architect)

### Сборка
1. Клонируйте репозиторий:
   ```bash
   git clone https://github.com/ваш-логин/pwmenager.git
