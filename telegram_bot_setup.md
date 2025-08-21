# Telegram Bot Setup (Guide)

1) In Telegram, chat with **@BotFather** → `/newbot` → get **Bot Token**.
2) Get your **chat ID** (e.g., via @userinfobot or by sending a message to the bot and using an API tool).
3) Put `TELEGRAM_BOT_TOKEN` and `TELEGRAM_CHAT_ID` in `firmware/config.h`.
4) In `flame_detector.ino`, enable the `sendTelegramAlert(...)` code block.