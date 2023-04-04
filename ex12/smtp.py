import smtplib
import re
import sys
from email.message import EmailMessage
import socket

SMTP_SERVER = ''
SMTP_PORT = 587
SMTP_USERNAME = ''
SMTP_PASSWORD = ''
SMTP_DOMAIN = ''

def is_valid_email(email):
    if re.match(r"[^@]+@[^@]+\.[^@]+", email):
        return True
    else:
        return False

def is_valid_domain(domain):
    try:
        socket.gethostbyname(domain)
        return True
    except:
        return False

while True:
    try:
        domain = input("Put the server: ")
    except (KeyboardInterrupt, EOFError):
        print("")
        sys.exit()
    except Exception as e:
        print(f"Error: {e}")
        sys.exit()
    if is_valid_domain(domain):
        SMTP_SERVER = domain
        break
    else:
        print('\nInvalid domain!\n')

while True:
    try:
        email_from = input("Put your email address: ")
    except (KeyboardInterrupt, EOFError):
        print("")
        sys.exit()
    except Exception as e:
        print(f"Error: {e}")
        sys.exit()
    if is_valid_email(email_from):
        SMTP_USERNAME = email_from
        SMTP_DOMAIN = email_from.split("@")[1]
        break
    else:
        print('\nInvalid email format!\n')

while True:
    try:
        email_to = input("Put the recipient email: ")
    except (KeyboardInterrupt, EOFError):
        print("")
        sys.exit()
    except Exception as e:
        print(f"Error: {e}")
        sys.exit()
    if is_valid_email(email_to):
        break
    else:
        print('\nInvalid email format!\n')

while True:
    try:
        password = input("Enter your email password: ")
    except (KeyboardInterrupt, EOFError):
        print("")
        sys.exit()
    except Exception as e:
        print(f"Error: {e}")
        sys.exit()
    if len(password) > 0:
        SMTP_PASSWORD = password
        break
    else:
        print('\nInvalid password!\n')

try:
    smtp_obj = smtplib.SMTP(SMTP_SERVER, SMTP_PORT, timeout=10)
    smtp_obj.ehlo(SMTP_DOMAIN)
    smtp_obj.starttls()
    smtp_obj.ehlo(SMTP_DOMAIN)
    smtp_obj.login(SMTP_USERNAME, SMTP_PASSWORD)

    message = EmailMessage()
    message['From'] = SMTP_USERNAME
    message['To'] = email_to
    message['Subject'] = '42SP'
    message.set_content('Hello!')

    with open('42.png', 'rb') as f:
        img = f.read()
        message.add_attachment(img, maintype='image', subtype='png', filename='42.png')

    try:
        smtp_obj.send_message(message)
    except smtplib.SMTPException as exception:
        print("Spam error! Please check that the sender email address is correct and that you have permission to send from it.")
    except Exception as e:
        print(f"Error: {e}")
        sys.exit()
except smtplib.SMTPAuthenticationError as exception:
    print("Error, invalid credentials!")
except Exception as e:
    print(f"Error: {e}")
    sys.exit()

smtp_obj.quit()