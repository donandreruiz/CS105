
farm.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <start_farm>:
   0:	55                   	push   %rbp
   1:	48 89 e5             	mov    %rsp,%rbp
   4:	b8 01 00 00 00       	mov    $0x1,%eax
   9:	5d                   	pop    %rbp
   a:	c3                   	retq   

000000000000000b <getval_294>:
   b:	55                   	push   %rbp
   c:	48 89 e5             	mov    %rsp,%rbp
   f:	b8 58 94 c3 95       	mov    $0x95c39458,%eax
  14:	5d                   	pop    %rbp
  15:	c3                   	retq   

0000000000000016 <getval_220>:
  16:	55                   	push   %rbp
  17:	48 89 e5             	mov    %rsp,%rbp
  1a:	b8 24 ca e6 58       	mov    $0x58e6ca24,%eax
  1f:	5d                   	pop    %rbp
  20:	c3                   	retq   

0000000000000021 <addval_349>:
  21:	55                   	push   %rbp
  22:	48 89 e5             	mov    %rsp,%rbp
  25:	89 7d fc             	mov    %edi,-0x4(%rbp)
  28:	8b 45 fc             	mov    -0x4(%rbp),%eax
  2b:	05 58 90 c3 72       	add    $0x72c39058,%eax
  30:	5d                   	pop    %rbp
  31:	c3                   	retq   

0000000000000032 <addval_355>:
  32:	55                   	push   %rbp
  33:	48 89 e5             	mov    %rsp,%rbp
  36:	89 7d fc             	mov    %edi,-0x4(%rbp)
  39:	8b 45 fc             	mov    -0x4(%rbp),%eax
  3c:	2d b4 76 38 3c       	sub    $0x3c3876b4,%eax
  41:	5d                   	pop    %rbp
  42:	c3                   	retq   

0000000000000043 <getval_251>:
  43:	55                   	push   %rbp
  44:	48 89 e5             	mov    %rsp,%rbp
  47:	b8 58 90 c2 40       	mov    $0x40c29058,%eax
  4c:	5d                   	pop    %rbp
  4d:	c3                   	retq   

000000000000004e <getval_319>:
  4e:	55                   	push   %rbp
  4f:	48 89 e5             	mov    %rsp,%rbp
  52:	b8 48 89 c7 c3       	mov    $0xc3c78948,%eax
  57:	5d                   	pop    %rbp
  58:	c3                   	retq   

0000000000000059 <getval_281>:
  59:	55                   	push   %rbp
  5a:	48 89 e5             	mov    %rsp,%rbp
  5d:	b8 0f 48 89 c7       	mov    $0xc789480f,%eax
  62:	5d                   	pop    %rbp
  63:	c3                   	retq   

0000000000000064 <addval_465>:
  64:	55                   	push   %rbp
  65:	48 89 e5             	mov    %rsp,%rbp
  68:	89 7d fc             	mov    %edi,-0x4(%rbp)
  6b:	8b 45 fc             	mov    -0x4(%rbp),%eax
  6e:	2d 71 b6 76 38       	sub    $0x3876b671,%eax
  73:	5d                   	pop    %rbp
  74:	c3                   	retq   

0000000000000075 <mid_farm>:
  75:	55                   	push   %rbp
  76:	48 89 e5             	mov    %rsp,%rbp
  79:	b8 01 00 00 00       	mov    $0x1,%eax
  7e:	5d                   	pop    %rbp
  7f:	c3                   	retq   

0000000000000080 <add_xy>:
  80:	55                   	push   %rbp
  81:	48 89 e5             	mov    %rsp,%rbp
  84:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  88:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  8c:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  90:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
  94:	48 01 d0             	add    %rdx,%rax
  97:	5d                   	pop    %rbp
  98:	c3                   	retq   

0000000000000099 <getval_477>:
  99:	55                   	push   %rbp
  9a:	48 89 e5             	mov    %rsp,%rbp
  9d:	b8 89 d1 20 c0       	mov    $0xc020d189,%eax
  a2:	5d                   	pop    %rbp
  a3:	c3                   	retq   

00000000000000a4 <setval_327>:
  a4:	55                   	push   %rbp
  a5:	48 89 e5             	mov    %rsp,%rbp
  a8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  ac:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  b0:	c7 00 81 ce 08 db    	movl   $0xdb08ce81,(%rax)
  b6:	5d                   	pop    %rbp
  b7:	c3                   	retq   

00000000000000b8 <addval_336>:
  b8:	55                   	push   %rbp
  b9:	48 89 e5             	mov    %rsp,%rbp
  bc:	89 7d fc             	mov    %edi,-0x4(%rbp)
  bf:	8b 45 fc             	mov    -0x4(%rbp),%eax
  c2:	2d 28 6e 76 31       	sub    $0x31766e28,%eax
  c7:	5d                   	pop    %rbp
  c8:	c3                   	retq   

00000000000000c9 <setval_136>:
  c9:	55                   	push   %rbp
  ca:	48 89 e5             	mov    %rsp,%rbp
  cd:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  d1:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  d5:	c7 00 48 99 e0 c3    	movl   $0xc3e09948,(%rax)
  db:	5d                   	pop    %rbp
  dc:	c3                   	retq   

00000000000000dd <addval_269>:
  dd:	55                   	push   %rbp
  de:	48 89 e5             	mov    %rsp,%rbp
  e1:	89 7d fc             	mov    %edi,-0x4(%rbp)
  e4:	8b 45 fc             	mov    -0x4(%rbp),%eax
  e7:	2d a4 b7 76 1f       	sub    $0x1f76b7a4,%eax
  ec:	5d                   	pop    %rbp
  ed:	c3                   	retq   

00000000000000ee <addval_103>:
  ee:	55                   	push   %rbp
  ef:	48 89 e5             	mov    %rsp,%rbp
  f2:	89 7d fc             	mov    %edi,-0x4(%rbp)
  f5:	8b 45 fc             	mov    -0x4(%rbp),%eax
  f8:	2d b8 76 1f 38       	sub    $0x381f76b8,%eax
  fd:	5d                   	pop    %rbp
  fe:	c3                   	retq   

00000000000000ff <addval_418>:
  ff:	55                   	push   %rbp
 100:	48 89 e5             	mov    %rsp,%rbp
 103:	89 7d fc             	mov    %edi,-0x4(%rbp)
 106:	8b 45 fc             	mov    -0x4(%rbp),%eax
 109:	2d 77 31 6f 3c       	sub    $0x3c6f3177,%eax
 10e:	5d                   	pop    %rbp
 10f:	c3                   	retq   

0000000000000110 <getval_489>:
 110:	55                   	push   %rbp
 111:	48 89 e5             	mov    %rsp,%rbp
 114:	b8 82 89 ce 94       	mov    $0x94ce8982,%eax
 119:	5d                   	pop    %rbp
 11a:	c3                   	retq   

000000000000011b <addval_316>:
 11b:	55                   	push   %rbp
 11c:	48 89 e5             	mov    %rsp,%rbp
 11f:	89 7d fc             	mov    %edi,-0x4(%rbp)
 122:	8b 45 fc             	mov    -0x4(%rbp),%eax
 125:	2d b8 76 1f 3c       	sub    $0x3c1f76b8,%eax
 12a:	5d                   	pop    %rbp
 12b:	c3                   	retq   

000000000000012c <getval_274>:
 12c:	55                   	push   %rbp
 12d:	48 89 e5             	mov    %rsp,%rbp
 130:	b8 48 89 e0 91       	mov    $0x91e08948,%eax
 135:	5d                   	pop    %rbp
 136:	c3                   	retq   

0000000000000137 <getval_151>:
 137:	55                   	push   %rbp
 138:	48 89 e5             	mov    %rsp,%rbp
 13b:	b8 89 d1 91 c3       	mov    $0xc391d189,%eax
 140:	5d                   	pop    %rbp
 141:	c3                   	retq   

0000000000000142 <setval_278>:
 142:	55                   	push   %rbp
 143:	48 89 e5             	mov    %rsp,%rbp
 146:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
 14a:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
 14e:	c7 00 89 d1 18 d2    	movl   $0xd218d189,(%rax)
 154:	5d                   	pop    %rbp
 155:	c3                   	retq   

0000000000000156 <addval_457>:
 156:	55                   	push   %rbp
 157:	48 89 e5             	mov    %rsp,%rbp
 15a:	89 7d fc             	mov    %edi,-0x4(%rbp)
 15d:	8b 45 fc             	mov    -0x4(%rbp),%eax
 160:	2d 57 2e df 2d       	sub    $0x2ddf2e57,%eax
 165:	5d                   	pop    %rbp
 166:	c3                   	retq   

0000000000000167 <setval_277>:
 167:	55                   	push   %rbp
 168:	48 89 e5             	mov    %rsp,%rbp
 16b:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
 16f:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
 173:	c7 00 89 c2 20 c0    	movl   $0xc020c289,(%rax)
 179:	5d                   	pop    %rbp
 17a:	c3                   	retq   

000000000000017b <addval_192>:
 17b:	55                   	push   %rbp
 17c:	48 89 e5             	mov    %rsp,%rbp
 17f:	89 7d fc             	mov    %edi,-0x4(%rbp)
 182:	8b 45 fc             	mov    -0x4(%rbp),%eax
 185:	2d b8 76 1f 38       	sub    $0x381f76b8,%eax
 18a:	5d                   	pop    %rbp
 18b:	c3                   	retq   

000000000000018c <setval_272>:
 18c:	55                   	push   %rbp
 18d:	48 89 e5             	mov    %rsp,%rbp
 190:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
 194:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
 198:	c7 00 48 89 e0 94    	movl   $0x94e08948,(%rax)
 19e:	5d                   	pop    %rbp
 19f:	c3                   	retq   

00000000000001a0 <getval_423>:
 1a0:	55                   	push   %rbp
 1a1:	48 89 e5             	mov    %rsp,%rbp
 1a4:	b8 89 ce 60 db       	mov    $0xdb60ce89,%eax
 1a9:	5d                   	pop    %rbp
 1aa:	c3                   	retq   

00000000000001ab <addval_383>:
 1ab:	55                   	push   %rbp
 1ac:	48 89 e5             	mov    %rsp,%rbp
 1af:	89 7d fc             	mov    %edi,-0x4(%rbp)
 1b2:	8b 45 fc             	mov    -0x4(%rbp),%eax
 1b5:	2d 67 3d df 3f       	sub    $0x3fdf3d67,%eax
 1ba:	5d                   	pop    %rbp
 1bb:	c3                   	retq   

00000000000001bc <getval_497>:
 1bc:	55                   	push   %rbp
 1bd:	48 89 e5             	mov    %rsp,%rbp
 1c0:	b8 65 89 ce c2       	mov    $0xc2ce8965,%eax
 1c5:	5d                   	pop    %rbp
 1c6:	c3                   	retq   

00000000000001c7 <getval_492>:
 1c7:	55                   	push   %rbp
 1c8:	48 89 e5             	mov    %rsp,%rbp
 1cb:	b8 30 89 ce c7       	mov    $0xc7ce8930,%eax
 1d0:	5d                   	pop    %rbp
 1d1:	c3                   	retq   

00000000000001d2 <setval_447>:
 1d2:	55                   	push   %rbp
 1d3:	48 89 e5             	mov    %rsp,%rbp
 1d6:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
 1da:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
 1de:	c7 00 89 d1 78 d2    	movl   $0xd278d189,(%rax)
 1e4:	5d                   	pop    %rbp
 1e5:	c3                   	retq   

00000000000001e6 <addval_384>:
 1e6:	55                   	push   %rbp
 1e7:	48 89 e5             	mov    %rsp,%rbp
 1ea:	89 7d fc             	mov    %edi,-0x4(%rbp)
 1ed:	8b 45 fc             	mov    -0x4(%rbp),%eax
 1f0:	2d 78 3d df 36       	sub    $0x36df3d78,%eax
 1f5:	5d                   	pop    %rbp
 1f6:	c3                   	retq   

00000000000001f7 <addval_283>:
 1f7:	55                   	push   %rbp
 1f8:	48 89 e5             	mov    %rsp,%rbp
 1fb:	89 7d fc             	mov    %edi,-0x4(%rbp)
 1fe:	8b 45 fc             	mov    -0x4(%rbp),%eax
 201:	2d 77 3d 6b 6f       	sub    $0x6f6b3d77,%eax
 206:	5d                   	pop    %rbp
 207:	c3                   	retq   

0000000000000208 <addval_458>:
 208:	55                   	push   %rbp
 209:	48 89 e5             	mov    %rsp,%rbp
 20c:	89 7d fc             	mov    %edi,-0x4(%rbp)
 20f:	8b 45 fc             	mov    -0x4(%rbp),%eax
 212:	2d 77 3d f7 36       	sub    $0x36f73d77,%eax
 217:	5d                   	pop    %rbp
 218:	c3                   	retq   

0000000000000219 <setval_254>:
 219:	55                   	push   %rbp
 21a:	48 89 e5             	mov    %rsp,%rbp
 21d:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
 221:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
 225:	c7 00 9c 89 d1 90    	movl   $0x90d1899c,(%rax)
 22b:	5d                   	pop    %rbp
 22c:	c3                   	retq   

000000000000022d <addval_331>:
 22d:	55                   	push   %rbp
 22e:	48 89 e5             	mov    %rsp,%rbp
 231:	89 7d fc             	mov    %edi,-0x4(%rbp)
 234:	8b 45 fc             	mov    -0x4(%rbp),%eax
 237:	2d 78 3d df 24       	sub    $0x24df3d78,%eax
 23c:	5d                   	pop    %rbp
 23d:	c3                   	retq   

000000000000023e <addval_287>:
 23e:	55                   	push   %rbp
 23f:	48 89 e5             	mov    %rsp,%rbp
 242:	89 7d fc             	mov    %edi,-0x4(%rbp)
 245:	8b 45 fc             	mov    -0x4(%rbp),%eax
 248:	2d 57 2e 6f 3c       	sub    $0x3c6f2e57,%eax
 24d:	5d                   	pop    %rbp
 24e:	c3                   	retq   

000000000000024f <getval_167>:
 24f:	55                   	push   %rbp
 250:	48 89 e5             	mov    %rsp,%rbp
 253:	b8 8d c2 38 d2       	mov    $0xd238c28d,%eax
 258:	5d                   	pop    %rbp
 259:	c3                   	retq   

000000000000025a <getval_250>:
 25a:	55                   	push   %rbp
 25b:	48 89 e5             	mov    %rsp,%rbp
 25e:	b8 89 c2 a4 db       	mov    $0xdba4c289,%eax
 263:	5d                   	pop    %rbp
 264:	c3                   	retq   

0000000000000265 <getval_140>:
 265:	55                   	push   %rbp
 266:	48 89 e5             	mov    %rsp,%rbp
 269:	b8 8b d1 c3 ab       	mov    $0xabc3d18b,%eax
 26e:	5d                   	pop    %rbp
 26f:	c3                   	retq   

0000000000000270 <setval_236>:
 270:	55                   	push   %rbp
 271:	48 89 e5             	mov    %rsp,%rbp
 274:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
 278:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
 27c:	c7 00 09 ce 84 c9    	movl   $0xc984ce09,(%rax)
 282:	5d                   	pop    %rbp
 283:	c3                   	retq   

0000000000000284 <getval_356>:
 284:	55                   	push   %rbp
 285:	48 89 e5             	mov    %rsp,%rbp
 288:	b8 48 89 e0 92       	mov    $0x92e08948,%eax
 28d:	5d                   	pop    %rbp
 28e:	c3                   	retq   

000000000000028f <end_farm>:
 28f:	55                   	push   %rbp
 290:	48 89 e5             	mov    %rsp,%rbp
 293:	b8 01 00 00 00       	mov    $0x1,%eax
 298:	5d                   	pop    %rbp
 299:	c3                   	retq   
