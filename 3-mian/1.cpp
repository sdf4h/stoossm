from selenium import webdriver
from selenium.webdriver.common.by import By
import time

driver = webdriver.Chrome()
driver.get("https://www.dobraya.su")

go_otziv = driver.find_element(By.XPATH, '/html/body/header/div[4]/div/div/div[1]/div/ul/li[7]/a')
go_otziv.click()

input_fio = driver.find_element(By.NAME, "fio")
input_fio.send_keys("Хакимов камиль айратович")
time.sleep(5)
input_email = driver.find_element(By.NAME, "phone")
input_email.send_keys("kamil@mail.com")
time.sleep(5)
vibor_stolovoy1 = driver.find_element(By.CLASS_NAME, "reviews__select")
vibor_stolovoy1.click()
time.sleep(5)
vibor_stolovoy2 = driver.find_element(By.XPATH, '//*[@id="reviews__box--select"]/option[1]')
vibor_stolovoy2.click()
time.sleep(5)
input_otziv = driver.find_element(By.NAME, "mess")
input_otziv.send_keys("Топ за свои деньги!")
time.sleep(5)
set_stars = driver.find_element(By.CLASS_NAME, "stars__span")
set_stars.click()
time.sleep(5)
send_otziv = driver.find_element(By.XPATH, "/html/body/main/div/div/div[1]/div[3]/form/div[5]/div[2]/button")
send_otziv.click()

