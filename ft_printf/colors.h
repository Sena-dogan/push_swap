/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sena <sena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 20:50:03 by zdogan            #+#    #+#             */
/*   Updated: 2023/04/22 22:03:13 by sena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H

# define COLORS_H

//Regular text
# define BLK "\e[0;30m"
# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define YEL "\e[19;33m"
# define BLU "\e[0;34m"
# define MAG "\e[0;35m"
# define CYN "c"
# define WHT "\e[0;37m"
# define MAG "\e[0;35m"
# define VIO "\e[0;34m"
# define PRPL "\e[0;53m"
# define MOR "\e[0;35m" //Magenta (mor)
# define LAV "\e[0;36m" //Lavanta (açık mor)
# define VIO "\e[0;34m" //Viyola (koyu maviye yakın mor)
# define PLM "\e[0;95m" //Palomino (pastel pembe-mor)
# define ORC "\e[0;38;5;129m" //Orchid (pembe-mor)
#define DNM "\e[0;38;5;60m" // Dark Magenta (koyu mor)
#define VRB "\e[0;38;5;92m" // Vibrant Purple (canlı mor)
#define PPL "\e[0;38;5;98m" // Purple (mor)
#define DMG "\e[0;38;5;135m" // Dark Magenta (koyu mor)
#define DOR "\e[0;38;5;53m" // Dark Orchid (koyu orkide)
#define CUSTOM "\033[38;2;35;17;35m"


//Regular bold text
# define BBLK "\e[1;30m"
# define BRED "\e[1;31m"
# define BGRN "\e[1;32m"
# define BYEL "\e[1;33m"
# define BBLU "\e[1;34m"
# define BMAG "\e[1;35m"
# define BCYN "\e[1;36m"
# define BWHT "\e[1;37m"
# define BMAG "\e[1;35m"
# define BVIO "\e[1;34m"
# define BORC "\e[1;38;5;129m"

# define BPRPL "\e[1;53m"

//Regular underline text
# define UBLK "\e[4;30m"
# define URED "\e[4;31m"
# define UGRN "\e[4;32m"
# define UYEL "\e[4;33m"
# define UBLU "\e[4;34m"
# define UMAG "\e[4;35m"
# define UCYN "\e[4;36m"
# define UWHT "\e[4;37m"

//Regular backgroundd
# define BLKB "\e[40m"
# define REDB "\e[41m"
# define GRNB "\e[42m"
# define YELB "\e[43m"
# define BLUB "\e[44m"
# define MAGB "\e[45m"
# define CYNB "\e[46m"
# define WHTB "\e[47m"

# define RST "\e[0m"
#endif