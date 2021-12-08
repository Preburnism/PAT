# -*- coding:utf-8 -*-
import urllib2
import urllib
import requests
import re
from bs4 import BeautifulSoup
import MySQLdb
import time


class PokeSearch:
    def __init__(self):
        # self.name = urllib.quote(name)  # 注意quote只接受ascii码，数据库提取出的是unicode，所以name需要先encode
        self.headers = {'Content-Type': 'application/x-www-form-urlencoded',
                        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/83.0.4103.97 Safari/537.36 Edg/83.0.478.45'}

    def getBasic(self, startpage):
        '''
        网页端
        url = startpage
        request = urllib2.Request(url, headers=self.headers)
        respond = urllib2.urlopen(request, timeout=100)
        time.sleep(0.5)
        html = respond.read()

        respond.close()
        soup = BeautifulSoup(html, 'lxml')
        '''

        # 本地html
        path = unicode(startpage, 'utf-8')
        with open(path, 'r') as f:
            soup = BeautifulSoup(f.read(), 'lxml')

        # instance
        tsql = ToSql()
        # 暂时存储一只宝可梦信息
        apoke = []

        temp = soup.find_all('table', attrs={'class': 'roundy eplist s-关都'})
        for tp in temp:
            poke_in_tp = tp.select('tr')
            for p in poke_in_tp:
                one_poke = p.select('td')
                if len(one_poke) > 0:
                    for unit in one_poke:
                        apoke.append(unit.get_text().strip())
                    if len(apoke[len(apoke) - 1]) > 1:
                        apoke[len(apoke) - 1] = ''
                    tsql.insertGuandu(apoke)
                    apoke = []

        temp = soup.find('table', attrs={'class': 'roundy eplist s-城都'})
        poke_in_tp = temp.select('tr')
        for p in poke_in_tp:
            one_poke = p.select('td')
            if len(one_poke) > 0:
                for unit in one_poke:
                    apoke.append(unit.get_text().strip())
                if len(apoke[len(apoke) - 1]) > 1:
                    apoke[len(apoke) - 1] = ''
                tsql.insertChengdu(apoke)
                apoke = []

        temp = soup.find('table', attrs={'class': 'roundy eplist s-豐緣'})
        poke_in_tp = temp.select('tr')
        for p in poke_in_tp:
            one_poke = p.select('td')
            if len(one_poke) > 0:
                for unit in one_poke:
                    apoke.append(unit.get_text().strip())
                if len(apoke[len(apoke) - 1]) > 1:
                    apoke[len(apoke) - 1] = ''
                tsql.insertFengyuan(apoke)
                apoke = []

        temp = soup.find('table', attrs={'class': 'roundy eplist s-神奧'})
        poke_in_tp = temp.select('tr')
        for p in poke_in_tp:
            one_poke = p.select('td')
            if len(one_poke) > 0:
                for unit in one_poke:
                    apoke.append(unit.get_text().strip())
                if len(apoke[len(apoke) - 1]) > 1:
                    apoke[len(apoke) - 1] = ''
                tsql.insertShenao(apoke)
                apoke = []

        temp = soup.find('table', attrs={'class': 'roundy eplist s-合眾'})
        poke_in_tp = temp.select('tr')
        for p in poke_in_tp:
            one_poke = p.select('td')
            if len(one_poke) > 0:
                for unit in one_poke:
                    apoke.append(unit.get_text().strip())
                if len(apoke[len(apoke) - 1]) > 1:
                    apoke[len(apoke) - 1] = ''
                tsql.insertHezhong(apoke)
                apoke = []

        temp = soup.find('table', attrs={'class': 'roundy eplist s-卡洛斯'})
        poke_in_tp = temp.select('tr')
        for p in poke_in_tp:
            one_poke = p.select('td')
            if len(one_poke) > 0:
                for unit in one_poke:
                    apoke.append(unit.get_text().strip())
                if len(apoke[len(apoke) - 1]) > 1:
                    apoke[len(apoke) - 1] = ''
                tsql.insertKaluosi(apoke)
                apoke = []

        temp = soup.find('table', attrs={'class': 'roundy eplist s-阿羅拉'})
        poke_in_tp = temp.select('tr')
        for p in poke_in_tp:
            one_poke = p.select('td')
            if len(one_poke) > 0:
                for unit in one_poke:
                    apoke.append(unit.get_text().strip())
                if len(apoke[len(apoke) - 1]) > 1:
                    apoke[len(apoke) - 1] = ''
                tsql.insertAluola(apoke)
                apoke = []

        temp = soup.find_all('table', attrs={'class': 'roundy eplist b-伽勒尔 bg-伽勒尔'})
        for tp in temp:
            poke_in_tp = tp.select('tr')
            for p in poke_in_tp:
                one_poke = p.select('td')
                if len(one_poke) > 0:
                    for unit in one_poke:
                        apoke.append(unit.get_text().strip())
                    if len(apoke[len(apoke) - 1]) > 1:
                        apoke[len(apoke) - 1] = ''
                    tsql.insertJialer(apoke)
                    apoke = []


class ToSql:
    def __init__(self):
        self.host = 'localhost'
        self.user = 'root'
        self.pw = '974607114'
        self.dbname = 'pokemon'
        self.charset = 'utf8'
        self.conn = MySQLdb.connect(self.host, self.user, self.pw, self.dbname, charset=self.charset)

    def insertGuandu(self, apoke):
        id_loc = int(apoke[0].replace('#', ''))
        id_all = int(apoke[1].replace('#', ''))

        cursor = self.conn.cursor()
        query = "insert into guandu(id_loc,id_all,name_cn,name_jp,name_en,attr1,attr2) values (%d,%d,'%s','%s','%s','%s','%s')" % (
            id_loc, id_all, apoke[3], apoke[4], apoke[5], apoke[6], apoke[7])

        try:
            cursor.execute(query)
            self.conn.commit()
        except:
            self.conn.rollback()

    def insertChengdu(self, apoke):
        id_loc_old = int(apoke[0].replace('#', ''))
        id_loc_new = int(apoke[1].replace('#', ''))
        id_all = int(apoke[2].replace('#', ''))

        cursor = self.conn.cursor()
        query = "insert into chengdu(id_loc_old,id_loc_new,id_all,name_cn,name_jp,name_en,attr1,attr2) values (%d,%d,%d,'%s','%s','%s','%s','%s')" % (
            id_loc_old, id_loc_new, id_all, apoke[4], apoke[5], apoke[6], apoke[7], apoke[8])

        try:
            cursor.execute(query)
            self.conn.commit()
        except:
            self.conn.rollback()

    def insertFengyuan(self, apoke):
        id_loc_old = int(apoke[0].replace('#', ''))
        id_loc_new = int(apoke[1].replace('#', ''))
        id_all = int(apoke[2].replace('#', ''))

        cursor = self.conn.cursor()
        query = "insert into fengyuan(id_loc_old,id_loc_new,id_all,name_cn,name_jp,name_en,attr1,attr2) values (%d,%d,%d,'%s','%s','%s','%s','%s')" % (
            id_loc_old, id_loc_new, id_all, apoke[4], apoke[5], apoke[6], apoke[7], apoke[8])

        try:
            cursor.execute(query)
            self.conn.commit()
        except:
            self.conn.rollback()

    def insertShenao(self, apoke):
        try:
            id_loc = int(apoke[0].replace('#', ''))
        except:
            id_loc = -1
        id_all = int(apoke[1].replace('#', ''))

        cursor = self.conn.cursor()
        query = "insert into shenao(id_loc,id_all,name_cn,name_jp,name_en,attr1,attr2) values (%d,%d,'%s','%s','%s','%s','%s')" % (
            id_loc, id_all, apoke[3], apoke[4], apoke[5], apoke[6], apoke[7])

        try:
            cursor.execute(query)
            self.conn.commit()
        except:
            self.conn.rollback()

    def insertHezhong(self, apoke):
        id_loc_old = int(apoke[0].replace('#', ''))
        id_loc_new = int(apoke[1].replace('#', ''))
        id_all = int(apoke[2].replace('#', ''))

        cursor = self.conn.cursor()
        query = "insert into hezhong(id_loc_old,id_loc_new,id_all,name_cn,name_jp,name_en,attr1,attr2) values (%d,%d,%d,'%s','%s','%s','%s','%s')" % (
            id_loc_old, id_loc_new, id_all, apoke[4], apoke[5], apoke[6], apoke[7], apoke[8])

        try:
            cursor.execute(query)
            self.conn.commit()
        except:
            self.conn.rollback()

    def insertKaluosi(self, apoke):
        try:
            id_loc_c = int(apoke[0].replace('#', ''))
        except:
            id_loc_c = -1
        try:
            id_loc_s = int(apoke[1].replace('#', ''))
        except:
            id_loc_s = -1
        try:
            id_loc_m = int(apoke[2].replace('#', ''))
        except:
            id_loc_m = -1
        id_all = int(apoke[3].replace('#', ''))

        cursor = self.conn.cursor()
        query = "insert into kaluosi(id_loc_center,id_loc_seaside,id_loc_mountain,id_all,name_cn,name_jp,name_en,attr1,attr2) values (%d,%d,%d,%d,'%s','%s','%s','%s','%s')" % (
            id_loc_c, id_loc_s, id_loc_m, id_all, apoke[5], apoke[6], apoke[7], apoke[8], apoke[9])

        try:
            cursor.execute(query)
            self.conn.commit()
        except:
            self.conn.rollback()

    def insertAluola(self, apoke):
        try:
            id_loc_old = int(apoke[0].replace('#', ''))
        except:
            id_loc_old = -1
        try:
            id_loc_new = int(apoke[1].replace('#', ''))
        except:
            id_loc_new = -1
        id_all = int(apoke[2].replace('#', ''))

        cursor = self.conn.cursor()
        query = "insert into aluola(id_loc_old,id_loc_new,id_all,name_cn,name_jp,name_en,attr1,attr2) values (%d,%d,%d,'%s','%s','%s','%s','%s')" % (
            id_loc_old, id_loc_new, id_all, apoke[4], apoke[5], apoke[6], apoke[7], apoke[8])

        try:
            cursor.execute(query)
            self.conn.commit()
        except:
            self.conn.rollback()

    def insertJialer(self, apoke):
        try:
            id_loc = int(apoke[0].replace('#', ''))
        except:
            id_loc = -1
        try:
            id_all = int(apoke[1].replace('#', ''))
        except:
            id_all = 99999

        cursor = self.conn.cursor()
        query = "insert into jialer(id_loc,id_all,name_cn,name_jp,name_en,attr1,attr2) values (%d,%d,'%s','%s','%s','%s','%s')" % (
            id_loc, id_all, apoke[3], apoke[4], apoke[5], apoke[6], apoke[7])

        try:
            cursor.execute(query)
            self.conn.commit()
        except:
            self.conn.rollback()

    def closeConn(self):
        self.conn.close()


if __name__ == '__main__':
    # startpage = 'https://wiki.52poke.com/wiki/%E5%AE%9D%E5%8F%AF%E6%A2%A6%E5%88%97%E8%A1%A8%EF%BC%88%E6%8C%89%E5%85%A8%E5%9B%BD%E5%9B%BE%E9%89%B4%E7%BC%96%E5%8F%B7%EF%BC%89'
    startpage = 'D:/Projects/Python/Poke/宝可梦列表（按全国图鉴编号） - 神奇宝贝百科，关于宝可梦的百科全书.html'
    ps = PokeSearch()
    ps.getBasic(startpage)
