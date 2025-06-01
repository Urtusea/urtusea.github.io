import { defineConfig } from 'vitepress'

// https://vitepress.dev/reference/site-config
export default defineConfig({
  title: "urtusea.github.io",
  description: "urtusea.github.io",
  head: [
    [
      'link',
      { rel: 'icon', href: '/icon.png' }
    ],
    [
      'link',
      { rel: 'preconnect', href: 'https://fonts.googleapis.com' }
    ],
    [
      'link',
      { rel: 'preconnect', href: 'https://fonts.gstatic.com', crossorigin: '' }
    ],
    [
      'link',
      { href: 'https://fonts.googleapis.com/css2?family=JetBrains+Mono:ital,wght@0,100..800;1,100..800&display=swap', rel: 'stylesheet' }
    ]
  ],
  // cleanUrls: true,

  themeConfig: {
    // https://vitepress.dev/reference/default-theme-config

    nav: [
      { text: '主页', link: '/' },
      { text: '随笔', link: '/note/' },
      { text: 'XCPC-Template', link: '/xcpc-template/' },
      { text: 'XCPC-Algorithm', link: '/xcpc-algorithm/' }
    ],

    sidebar: {
      '/note/' : [
        {
          text: '随笔',
          items: [
            {
              text: 'XCPC-游记',
              collapsed: true,
              items: [
                { text: '2025 CCPC 山东省赛', link: 'note/XCPC/2025-CCPC-shandong' }
              ]
            }
          ]
        }
      ],

      '/xcpc-template/': [
        {
          text: 'XCPC-Template',
          items: [
            {
              text: '前言',
              link: '/xcpc-template/'
            },
            {
              text: '数据结构',
              collapsed: true,
              items: [
                {
                  text: '并查集',
                  collapsed: true,
                  items: [
                    { text: 'Disjoint Union Set - 并查集', link: '/xcpc-template/data_structure/disjoint_union_set/disjoint_union_set'},
                    { text: 'Disjoint Union Set Range - 倍增并查集', link: '/xcpc-template/data_structure/disjoint_union_set/disjoint_union_set_range'}
                  ]
                },
                {
                  text: '树状数组',
                  collapsed: true,
                  items: [
                    { text: 'Fenwick Tree - 树状数组', link: '/xcpc-template/data_structure/fenwick_tree/fenwick_tree' },
                    { text: 'Fenwick Tree 2D - 二维树状数组', link: '/xcpc-template/data_structure/fenwick_tree/fenwick_tree_2D' }
                  ]
                },
                {
                  text: '线段树',
                  collapsed: true,
                  items: [
                    { text: 'Segment Tree - 单点修改线段树', link: '/xcpc-template/data_structure/segment_tree/segment_tree' },
                    { text: 'Segment Tree Lazy - 懒标记线段树', link: '/xcpc-template/data_structure/segment_tree/segment_tree_lazy' }
                  ]
                },
                {
                  text: 'Bit字典树',
                  collapsed: true,
                  items: [
                    { text: 'Bit Trie - Bit字典树', link: '/xcpc-template/data_structure/bit_trie/bit_trie'}
                  ]
                },
                {
                  text: '珂朵莉树',
                  collapsed: true,
                  items: [
                    { text: 'Chtholly Tree - 珂朵莉树', link: '/xcpc-template/data_structure/chtholly_tree/chtholly_tree'}
                  ]
                }
              ]
            },
            {
              text: '图论',
              collapsed: true,
              items: [
                {
                  text: '连通分量',
                },
                {
                  text: '树论',
                  collapsed: true,
                  items: [
                    { text: 'Lowest Common Ancestor - DFN序最近公共祖先', link: '/xcpc-template/graph/tree/lowest_common_ancestor' }
                  ]
                },
              ]
            },
            {
              text: '线性代数',
              collapsed: true,
              items: [
                {
                  text: '矩阵类',
                  collapsed: true,
                  items: [
                    { text: 'Matrix 2x2 - 2x2矩阵类', link: '/xcpc-template/linear_algebra/matrix/matrix_2x2' }
                  ]
                },
              ]
            },
            {
              text: '数论',
              collapsed: true,
              items: [
                {
                  text: '模数类',
                  collapsed: true,
                  items: [
                    { text: 'Mod Int - 模数类', link: '/xcpc-template/number_theory/mod_int/mod_int' }
                  ]
                },
              ]
            },
          ]
        }
      ],

      '/xcpc-algorithm/': [
        {
          text: 'XCPC-Algorithm',
          items: [
          ]
        }
      ]
    },

    socialLinks: [
      { icon: 'github', link: 'https://github.com/Urtusea/urtusea.github.io/' }
    ],

    outline: {
      label: '页面导航'
    },
  }
})
